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

const int maxn = 2e4 + 10, Max = 4e3 + 10, mod = 1e9 + 7;
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

vector<pii> tdo[4 * maxn];
vector<pii> qur[maxn];
int ans[maxn];

void add(int f, int s, pii p, int l = 0, int r = maxn, int id = 1){
    if(f >= s || l >= r || s <= l || r <= f)
	return;
    if(f <= l && r <= s){
	tdo[id].PB(p);
	return;
    }
    int mid = (l+r) >> 1;
    add(f, s, p, l, mid, 2*id);
    add(f, s, p, mid, r, 2*id+1);
}

int dp[Max];
vector<pii> fback;

void solve(int l = 0, int r = maxn, int id = 1){
    for(pii p : tdo[id]){
	for(int i = Max-1; i >=0; i--){
	    if(i >= p.F && dp[i - p.F] + p.S > dp[i])
		fback.PB({i, dp[i]}), dp[i] = dp[i - p.F] + p.S;
	}
    }
    if(r-l == 1){
	for(pii p : qur[l])
	    ans[p.S] = dp[p.F];
	return;
    }
    int mid = (l+r) >> 1;
    int SZ = sz(fback);
    solve(l, mid, 2*id);
    while(sz(fback) > SZ){
	dp[ fback.back().F ] = fback.back().S;
	fback.pop_back();
    }
    solve(mid, r, 2*id+1);   
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, p;
    cin >> n >> p;
    for(int i = 0; i < n; i++){
	int c, h, t;
	cin >> c >> h >> t;
	add(t, t+p, (pii){c, h});	
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
	int t, c;
	cin >> t >> c;
	qur[t].PB({c, i});
    }
    solve();
    for(int i = 0; i < q; i++)
	cout << ans[i] << "\n";
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")