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

const int maxn = 1e5 + 10, mod = 1e9 + 7;
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

int dp[maxn], f[maxn], z[maxn];
ll ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    string a, b;
    cin >> a >> b;
    for(int i = 1; i < sz(b); i++){
	f[i] = f[i-1];
	while(f[i] != 0 && b[ f[i] ] != b[i])
	    f[i] = f[ f[i]-1 ];
	f[i]+= b[ f[i] ] == b[i];
    }
    int L = -1, R = -1;
    z[0] = sz(b);
    for(int i = 1; i < sz(b); i++){
	if(R <= i){
	    L = R = i;
	    while(R < sz(b) && b[R] == b[R-i])
		R++;
	    z[i] = R-i;
	}
	z[i] = min(R-i, z[i-L]);
	while(i + z[i] < sz(b) && b[i + z[i]] == b[z[i]])
	    z[i]++;
	if(R < i + z[i])
	    L = i, R = i + z[i];
    }
    for(int i = 0; i < sz(b); i++){
	dp[i] = max( f[i] == 0 ? 0 : dp[ f[i]-1 ], z[i+1] );
    }
    int tmp = 0;
    for(int i = 0; i < sz(a); i++){
	while(tmp != 0 && a[i] != b[tmp])
	    tmp = f[ tmp-1 ];
	tmp+= a[i] == b[tmp];
	ans+= tmp == 0 ? sz(b) : (sz(b) - dp[tmp-1]);
    }
    int lcp = 0;
    while(lcp < sz(a) && lcp < sz(b) && a[lcp] == b[lcp])
	lcp++;
    for(int i = 0; i < sz(b); i++){
	if(f[i] != 0 && i+1-f[i] <= lcp)
	    ans++;
    }
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")