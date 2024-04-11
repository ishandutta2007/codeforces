// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=15e4 + 10, mod=998244353;

vector<int> v[maxn];
int SZ[maxn], pr[maxn], n;
int valf[maxn], valf2[maxn];

int arr1[maxn], arr2[maxn];
int fac[maxn], ifac[maxn];

int dp1[maxn], dp2[maxn];

void prep(int u, int par=0){
    pr[u] = par;
    SZ[u] = 1;
    for(int y : v[u]){
	if(y != par)
	    prep(y, u), SZ[u] += SZ[y];
    }
}
int Pow(int a, int b){
    int ans = 1;
    for(; b; b>>=1, a= 1ll*a*a %mod)
	if(b&1)
	    ans = 1ll* ans* a %mod;
    return ans;
}
int C(int n, int k){
    if( k<0 || n<0 || n<k) return 0;
    return 1ll * fac[n] * ifac[k] %mod * ifac[n-k] %mod;
}

int w[2][maxn];

void fft(int *arr, int n, bool rev){
    int N = __builtin_ctz(n);
    for(int i = 0; i < n; i++){
	int x = 0;
	for(int j = 0; j < N; j++)
	    x += bit(i, j) << (N- 1- j);
	if(x < i)
	    swap(arr[x], arr[i]);
    }

    w[0][0] = 1;
    w[0][1] = Pow( 3, ( mod -1 ) >> (N) );
    for(int i = 2; i < n; i++)
	w[0][i] = 1ll * w[0][i-1] * w[0][1] %mod;
    w[1][0] = 1;
    w[1][1] = Pow( w[0][1], mod - 2 );
    for(int i = 2; i < n; i++)
	w[1][i] = 1ll * w[1][i-1] * w[1][1] %mod;
    
    for(int stpid = 0; stpid < N; stpid++){
	int stp = 1<<stpid;
	for(int l = 0; l < n; l+= stp + stp){
	    for(int i = 0; i < stp; i++){
		int &A = arr[l + i], &B = arr[l + stp + i], C = 1ll * B * w[rev][i << (N - stpid -1)] %mod;
		B = ( A - C ) %mod;
		A = ( A + C ) %mod;
	    }
	}
    }

    if(rev){
	int rv = Pow( n, mod - 2 );
	for(int i = 0; i < n; i++)
	    arr[i] = 1ll * arr[i] * rv %mod;
    }
}

void calc(vector<int> &vec){
    int n = sz(vec);
    for(int i = 0; i < n; i++)
	valf[i] = vec[i];
    while( __builtin_popcount(n) != 1 )
	valf[n++] = 0;
    for(int stp = 1; stp < n; stp*=2){
	for(int l = 0; l < n; l+= stp + stp){
	    fill( arr1, arr1 + 2 * stp, 0);
	    fill( arr2, arr2 + 2 * stp, 0);
	    arr1[0] = arr2[0] = 1;
	    for(int i = 0; i < stp; i++){
		arr1[i+1] = valf[l + i];		
		arr2[i+1] = valf[l + stp + i];
	    }
	    fft(arr1, stp*2, 0);
	    fft(arr2, stp*2, 0);
	    for(int i = 0; i < stp*2; i++)
		arr1[i] = 1ll * arr1[i] * arr2[i] %mod;
	    fft(arr1, stp*2, 1);
	    for(int i = 0; i < stp*2 -1; i++)
		valf[l + i] = arr1[i+1];
	    valf[l + stp*2 -1] = (arr1[0] - 1) %mod;
	}
    }
    for(int i = n; i > 0; i--)
	valf[i] = valf[i-1];
    valf[0] = 1;
}

int ANS, NW;

void dfs(int u, int par=-1){
    ANS = ( ANS + 1ll * dp1[u] * NW ) %mod;
    for(int y : v[u]){
	if( y != par ){
	    NW = ( NW + dp2[y] ) %mod;
	    dfs( y, u );
	    NW = ( NW - dp2[y] ) %mod;
	}	
    }
    NW = ( NW + dp1[u] ) %mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    fac[0] = 1;
    for(int i = 1; i < maxn; i++)
	fac[i] = 1ll * i * fac[i-1] %mod;
    ifac[ maxn - 1 ] = Pow( fac[maxn - 1], mod - 2 );
    for(int i = maxn - 2; i >= 0; i--)
	ifac[i] = 1ll * (i+1) * ifac[i+1] %mod;
    
    int k;
    cin >> n >> k;

    for(int i = 0; i < n-1; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);
    }

    if( k == 1 )
	return cout << ( ( 1ll * n * (n-1) ) / 2 ) %mod << endl, 0;
    
    prep(1);

    for(int u = 1; u <= n; u++){
	vector<int> vec;
	map<int, int> mp;
	
	for(int y : v[u]){
	    if(y == pr[u])
		vec.PB( n - SZ[u] );
	    else
		vec.PB( SZ[y] );
	}
	calc(vec);

	for(int y : v[u]){
	    int s = ( y == pr[u] ) ? (n - SZ[u]) : (SZ[y]);

	    if(mp.count(s) == 0){
		valf2[0] = 1;
		for(int i = 1; i <= sz(v[u]); i++){
		    valf2[i] = ( 1ll * valf[i] - 1ll * s * valf2[i-1] ) %mod;
		}
		int DP = 0;
		for(int i = 0; i < sz(v[u]); i++){
		    DP = ( 1ll * DP + 1ll * C(k, i) * fac[i] %mod * valf2[i] ) % mod;
		}
		mp[s] = DP;
	    }
	    if( y == pr[u] )
		dp1[u] = mp[s];
	    else
		dp2[y] = mp[s];
	}
    }
    dfs(1);
    if( ANS < 0 )
	ANS = ( ANS + mod ) %mod;
    return cout << ANS << endl, 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")