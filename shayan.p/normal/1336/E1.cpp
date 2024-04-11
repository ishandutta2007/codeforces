// Never let them see you bleed...
// Shayan.P  2020-04-17

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 36, DV = 20, mod = 998244353;

ll a[maxn];
ll XR[1<<DV];
int ans[maxn], dp[maxn][1<<(maxn-DV)];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < n; i++){
	ll x;
	cin >> x;
	for(int j = 0; j < maxn; j++){
	    if(bit(x, j))
		x^= a[j];
	}
	if(x == 0){
	    cnt++;	    
	}
	else{
	    int id = __builtin_ctzll(x);
	    a[id] = x;
	    for(int j = 0; j < maxn; j++){
		if(j != id && bit(a[j], id))
		    a[j]^= x;
	    }
	}
    }
    vector<ll> vec;
    ll MSK = (1ll<<m) - 1;
    for(int i = 0; i < maxn; i++){
	if(a[i] != 0)
	    MSK^= 1ll<<i, vec.PB(a[i]);
    }
    if(sz(vec) <= DV){
	ans[0]++;
	for(int msk = 1; msk < (1<<sz(vec)); msk++){
	    XR[msk] = XR[msk ^ (msk & -msk)] ^ vec[__builtin_ctz(msk)];
	    ans[__builtin_popcountll(XR[msk])]++;
	}
    }
    else{
	for(ll &x : vec){
	    ll y = 0;
	    int c = 0;
	    for(int i = 0; i < maxn; i++){
		if(bit(MSK, i)){
		    y+= bit(x, i) << c;
		    c++;
		}
	    }
	    x = y;
	}
	int c = __builtin_popcountll(MSK);
	
	dp[0][0] = 1;
	for(int x : vec){
	    for(int i = maxn-1; i > 0; i--){
		for(int msk = 0; msk < (1<<c); msk++)
		    dp[i][msk] = (dp[i][msk] + dp[i-1][msk ^ x]) % mod;
	    }
	}
	for(int i = 0; i < maxn; i++){
	    for(int msk = 0; msk < (1<<c); msk++){
		ans[i + __builtin_popcount(msk)] = (ans[i + __builtin_popcount(msk)] + dp[i][msk]) % mod;
	    }
	}
    }
    int pw = 1;
    for(int i = 0; i < cnt; i++){
	pw = 2ll * pw % mod;
    }
    for(int i = 0; i <= m; i++){
	cout << 1ll * pw * ans[i] % mod << " ";
    }
    return cout << endl, 0;
}