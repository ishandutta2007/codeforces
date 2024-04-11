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

const int maxn = 1e5 + 10, inf = 1e9 + 10;

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

int a[maxn], mnl[maxn], n, s, m;
bool b[maxn];

int cnt[maxn];
pii dp[maxn];

pii bst(int x){
    cnt[0] = 0;
    dp[0] = {0,0};
    if(x == 0){
	int ans = 0;
	for(int i = 0; i < n; i++){
	    if(mnl[i] <= i)
		ans+= b[i] == 0;
	}
	return {ans, s};
    }
    for(int i = 0; i < n; i++){
	cnt[i+1] = cnt[i] + (b[i] == 0);
    }
    for(int i = 0; i < n; i++){
	dp[i+1] = dp[i];
	if(mnl[i] > i)
	    continue;
	dp[i+1] = max( dp[i], (pii){ cnt[i+1] - cnt[ mnl[i] ] + x + dp[ mnl[i] ].F, dp[ mnl[i] ].S + 1 } );
    }
    return dp[n];
}
int solve(){
    if(m == s){
	int ans = 0;
	for(int i = 0; i < n; i++){
	    if(mnl[i] <= i)
		ans+= b[i] == 0;
	}
	return ans;
    }
    int l = -n, r = 0;
    while(r-l > 1){
	int mid = (l+r) /2;
	pii p = bst(mid);
	if(p.S == m)
	    return p.F - m * mid;
	if(p.S < m)
	    l = mid;
	else
	    r = mid;
    }
    pii p = bst(r);
    return p.F - m * r;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int k;
    cin >> n >> s >> m >> k;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	mnl[i] = n;
    }
    for(int i = 0; i < s; i++){
	int l, r;
	cin >> l >> r;
	--l, --r;
	mnl[r] = min(mnl[r], l);
    }
    for(int i = n-2; i >= 0; i--){
	mnl[i] = min( mnl[i], mnl[i+1] );
    }
    int l = 0, r = inf;
    while(r-l > 1){
	int mid = (l+r) >> 1;
	for(int i = 0; i < n; i++)
	    b[i] = a[i] > mid;
	if(solve() >= k)
	    r = mid;
	else
	    l = mid;
    }
    if(r == inf)
	return cout << -1 << endl, 0;
    return cout << r << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")