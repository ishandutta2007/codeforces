#include <bits/stdc++.h>
#define	ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
//#define int long long
#define ld long double
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std; 
const int N = 1e5 + 100, OO = 1e9 + 7, T = 22, M = 1e9 + 7, P = 6151, SQ = 1300, lg = 22;
typedef pair <int, int> pii;
int mark[N], deg[N], ct[N];
bool ans[N], can[N];
vector <int> v[N], A;
vector <pii> ch[N];
bool cmp(int x, int y) {
	return mark[x] < mark[y];
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	A.clear();
	for(int i = 0; i <= n; i++)
	    v[i].clear(), ch[i].clear(), mark[i] = deg[i] = ct[i] = 0, ans[i] = can[i] = false;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	if(k > 500) {
	   cout << -1 << endl;
	   return;
	}
	set <pii> st;
	for(int i = 1; i <= n; i++)
		st.insert({deg[i] = (int)v[i].size(), i});
	int cnt = 1;
	while((int)st.size()) {
		pii p = *st.begin();
		if(p.ff >= k) {
			cout << 1 << " " << (int)st.size() << endl;
			for(auto u : st)
				cout << u.ss << " ";
			cout << endl;
			return;
		}
		else {
			st.erase(p);
			mark[p.ss] = cnt;
			for(auto u : v[p.ss])
				if(!mark[u])
					st.erase({deg[u], u}), st.insert({--deg[u], u});
			A.pb(p.ss);
		}
		cnt++;
	}
	for(auto i : A) {
		int nxt = 0;
		for(auto u : v[i]) 
			if(mark[u] > mark[i])
				ct[nxt++] = u, can[u] = true;
		for(auto u : ch[i]) 
			if(!can[u.ff])
				ans[u.ss] = false;
		for(int j = 0; j < nxt; j++)
			can[ct[j]] = false;
		if(nxt != k - 1)
			continue;
		ans[i] = true;
		sort(ct, ct + nxt, cmp);
		for(int j = 0; j < nxt; j++)
			for(int k = j + 1; k < nxt; k++)
				ch[ct[j]].pb({ct[k], i});
	}
	for(auto i : A) {
		if(!ans[i])
			continue;
		cout << 2 << endl;
		cout << i << " ";
		for(auto u : v[i])
			if(mark[u] > mark[i])
				cout << u << " ";
		cout << endl;
		return;
	}
	cout << -1 << endl;
	return;
}

int32_t main() {
	use_fast;
	int t;
    cin >> t;
    while(t--)
        solve();
	return 0;
}