#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
#define INF 10000000000000000LL
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
vi e[MN];
ll a[MN], b[MN];
ll dp[MN];
int sz[MN];

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
        if(empty()) return 0;
		//assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

LineContainer hmm[MN];
void dfs(int cn, int p){
    ll ans = 0;
    for(auto nn : e[cn]) if(nn != p){
        dfs(nn, cn);
        
        if(sz[nn] > sz[cn]){
            swap(hmm[cn], hmm[nn]);
        }

        for(auto u : hmm[nn]){
            hmm[cn].add(u.k, u.m);
        }
        sz[cn] += sz[nn];
    }
    
    dp[cn] = -hmm[cn].query(a[cn]);
    hmm[cn].add(-b[cn], -dp[cn]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
    }
    FOR(i, 1, n) cin >> b[i];
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(1, 0);
    FOR(i, 1, n){
        cout << dp[i] << " ";
    }
    cout << "\n";

    return 0;
}