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

const int maxn = 1010, mod = 1e9 + 7;
const ll inf = 1e18 + 10;

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

int rnk[maxn][maxn], arr[maxn];
int nxt[maxn];
ll dp[maxn][maxn], sm[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    ll k;
    cin >> k;
    string s;
    cin >> s;
    
    for(int i = 0; i < n; i++){
	rnk[i][i] = s[i] - 'a';
    }
    for(int ln = 2; ln <= n; ln++){
	for(int l = 0; l < n-ln+1; l++)
	    arr[l] = l;
	auto cmp = [&](int i, int j){
		       if(rnk[i][i+ln-2] == rnk[j][j+ln-2])
			   return s[i+ln-1] < s[j+ln-1];
		       return rnk[i][i+ln-2] < rnk[j][j+ln-2];
		   };
	sort(arr, arr+n-ln+1, cmp);
	for(int i = 1; i < n-ln+1; i++)
	    rnk[ arr[i] ][ arr[i]+ln-1 ] = rnk[ arr[i-1] ][ arr[i-1]+ln-1 ] + cmp(arr[i-1], arr[i]);
    }
    vector<pii> seg;
    for(int l = 0; l < n; l++){
	for(int r = l; r < n; r++)
	    seg.PB({l, r});
    }
    sort(seg.begin(), seg.end(), [&](pii a, pii b){
				     int SZ = min(a.S - a.F +1, b.S - b.F + 1);
				     if(rnk[a.F][a.F + SZ-1] != rnk[b.F][b.F + SZ-1])
					 return rnk[a.F][a.F + SZ-1] < rnk[b.F][b.F + SZ-1];
				     if(a.S - a.F != b.S - b.F)
					 return a.S - a.F < b.S - b.F;
				     return false;
				 });
    int l = 0, r = n * (n+1) / 2;
    while(r-l > 1){
        int mid = (l+r) >> 1;
        for(int i = 0; i < n; i++)
	    nxt[i] = n+1;
	for(int i = (n * (n+1) / 2) -1; i >= mid; i--)
	    nxt[ seg[i].F ] = seg[i].S + 1;
	memset(dp, 0, sizeof dp);
	dp[n][0] = 1;
	sm[n][0] = 1;
	for(int i = n-1; i >= 0; i--){
	    for(int j = 1; j <= m; j++){
		dp[i][j] = sm[nxt[i]][j-1];
		sm[i][j] = sm[i+1][j] + dp[i][j];
		sm[i][j] = min(sm[i][j], inf);		
	    }
	    sm[i][0] = 1;
	}
	if(dp[0][m] < k)
	    r = mid;
	else
	    l = mid;
    }
    return cout << s.substr( seg[l].F, seg[l].S - seg[l].F + 1 ) << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")