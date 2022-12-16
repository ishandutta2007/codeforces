// So when you feel like hope is gone, Look inside you and be strong, And you'll finally see the truth, That a hero lies in you ... 
 
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

const int maxn = 255, mod = 998244353;
const ll inf = 1e18;

template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> p){
    out << "{ " << p.F << ", " << p.S <<" }";
    return out;
}
template<typename T> ostream& operator << (ostream& out, vector<T> v){
    out << "[ ";
    for(int i = 0; i < sz(v); i++){
	out << v[i];
	if(i != sz(v)-1)
	    out << " ,";
    }
    out << " ]";
    return out;
}

int f[maxn], a[maxn], b[maxn];
bool bada[maxn], badb[maxn];
bool mark[maxn], mark2[maxn];

int cnt[4];

int poly[maxn];

void add(int c){// x + c
    for(int i = maxn-1; i > 0; i--)
	poly[i] = ( 1ll * poly[i-1] + 1ll * c * poly[i] ) % mod;
    poly[0] = 1ll * poly[0] * c % mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
	cin >> a[i];	
    }
    for(int i = 1; i <= n; i++){
	cin >> b[i];
    }
    int pre = 0, cof = 1, E = 0; // A : khorroji kharab // B : voroodi kharab
    for(int i = 1; i <= n; i++){
	if(a[i] == 0 && b[i] == 0){
	    ++E;
	    cof = 1ll * cof * E % mod;
	}
	else if(a[i] == 0){
	    badb[ b[i] ] = 1;
	}
	else if(b[i] == 0){
	    bada[ a[i] ] = 1;
	}
	else{
	    f[ a[i] ] = b[i];
	    mark2[ b[i] ] = 1;
	}
    }
    for(int i = 1; i <= n; i++){
	if(mark2[i])
	    continue;
	if(mark[i] == 0){
	    int tmp = i;
	    while(f[tmp] != 0){
		mark[tmp] = 1;
		tmp = f[tmp];
	    }
	    mark[tmp] = 1;
	    cnt[ 2 * bada[tmp] + badb[i] ]++;
	}
    }
    for(int i = 1; i <= n; i++){
	if(mark[i])
	    continue;
	int tmp = i;
	pre++;
	while(mark[tmp] == 0)
	    mark[tmp] = 1, tmp = f[tmp];
    }
    /*    cout <<"SALAM "<<cof << " " << pre << " "<< endl;
    for(int i = 0; i < 4; i++)
    	cout << cnt[i] << endl;
    return 0;
    */
    poly[0] = 1;
    
    for(int i = 0; i < cnt[0]; i++){
	add(i);
    }
    for(int i = 0; i < cnt[3]; i++){
	cof = 1ll * cof * (cnt[0] - i) % mod;
    }
    for(int i = 0; i < cnt[2]; i++){
	add(cnt[0] + i);
    }
    for(int i = 0; i < cnt[1]; i++){
	add(cnt[0] + i);
    }
    
    for(int i = 0; i < pre; i++){
	add(0);
    }
    for(int i = n; i >= 1; i--){
	cout << 1ll * poly[i] * cof % mod << " ";
    }
    return cout << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")