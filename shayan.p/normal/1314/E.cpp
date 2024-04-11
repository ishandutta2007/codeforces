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

const int maxn = 2030, mod = 998244353, SQ = 70;

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

int n, k;

vector<int> f(vector<int> v){
    //    sort(v.begin(), v.end()); is it necassary ?!
    vector<int> ret;
    int C = 1;
    while(sz(v)){
	int x = v.back();
	v.pop_back();
	while(x--)
	    ret.PB(C);
	C++;
    }
    return ret;
}

map<vector<int> , int> mp;

int g(vector<int> v){
    if(mp.count(v))
	return mp[v];
    if(sz(v) == 1 && v[0] == 1)
	return mp[v] = 2025;// inf
    if(sz(f(v)) > n)
	return mp[v] = 0;
    return mp[v] = g(f(v)) + 1;
}

vector<int> vec;
int ans = 0;

void go(){
    for(int i = sz(vec) ? vec.back() : 1; ; i++){
	vec.PB(i);
	if(g(vec) >= k){
	    ans++;
	    go();
	}
	else{
	    vec.pop_back();
	    return;
	}
	vec.pop_back();
    }
}

vector<int> vec2;

bool ok(){
    vec2 = f(vec);
    ll ans = 0;
    for(int i = 0; i < sz(vec2); i++)
	ans+= 1ll * (sz(vec2)-i) * vec2[i];
    return ans <= n;
}
void go3(){
    for(int i = sz(vec) ? vec.back() : 1; ; i++){
	vec.PB(i);
	if(ok()){
	    ans++;
	    go3();
	}
	else{
	    vec.pop_back();
	    return;
	}
	vec.pop_back();
    }
}

int dp[maxn][maxn]; // sum // max
int dp2[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin >> n >> k;

    if(k == 1){
	dp[0][0] = 1;
	for(int i = 0; i <= n; i++){
	    for(int j = 1; j <= n; j++){
		dp[i][j] = dp[i][j-1];
		if(j <= i)
		    dp[i][j] = (dp[i][j] + dp[i-j][j]) % mod;
	    }
	}
	for(int i = 1; i <= n; i++)
	    ans = (ans + dp[i][n]) % mod;     
    }
    if(k == 2){
	for(int w = n; w >= 1; w--){
	    for(int i = w; i <= n; i++)
		for(int j = 1; w * j <= i; j++)
		    dp2[i][j] = dp[i][j], dp[i][j] = 0;
	    for(int i = w; i <= n; i++)
		dp[i][1]++;
	    for(int i = w; i <= n; i++)
		for(int j = 2; w * j <= i; j++)
		    dp[i][j]= (((dp[i][j] + dp2[i][j]) %mod) + dp[i - w * j][j-1]) % mod;
	}
	for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= n; j++)
		ans= (ans + dp[i][j]) % mod;
    }
    if(k == 3){
	go3();
    }
    if(k > 3){
	go();
    }
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")