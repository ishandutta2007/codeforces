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

const int maxn = 88, maxk = 15, inf = 15e8;

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

int dp[maxk][maxn], a[maxn][maxn];
bool p[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
	    cin >> a[i][j];
    mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());
    int TDO = 3000;
    int ANS = inf;
    while(TDO--){
	for(int i = 0; i < n; i++)
	    dp[0][i] = inf;
	dp[0][0] =0;
	for(int i = 1; i < n; i++)
	    p[i] = uniform_int_distribution<int>(0, 1)(rng);
	for(int i = 1; i <= k; i++){
	    for(int j = 0; j < n; j++){
		dp[i][j] = inf;
		if(p[j] != (i & 1))
		    continue;
		for(int w = 0; w < n; w++)
		    dp[i][j] = min(dp[i][j], dp[i-1][w] + a[w][j]);
	    }
	}
	ANS = min(ANS, dp[k][0]);
    }
    return cout << ANS << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")