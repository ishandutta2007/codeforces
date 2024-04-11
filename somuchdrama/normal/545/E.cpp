#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1000000000000000;

int main() {
	ll n, m;
	cin >>n >> m;
	vector < vector < pair<ll,ll> > > g (n);
	unordered_map<ll, pair<ll, ll> > A;
	for(ll i = 0; i < m; ++i){
        ll s, t;
        ll l;
        cin >>s >>t >> l;
        --t;--s;
        g[s].push_back(make_pair(t, l));
        g[t].push_back(make_pair(s, l));
        A[s * 1e6 + t] = make_pair(i + 1, l);
        A[t * 1e6 + s] = make_pair(i + 1, l);
	}
	ll s;
	cin >> s;
	--s;
	vector<ll> d (n, INF),  p (n, -1);
	d[s] = 0;
	set < pair<ll,ll> > q;
	q.insert (make_pair (d[s], s));
	while (!q.empty()) {
		ll v = q.begin()->second;
		q.erase (q.begin());
		for (size_t j=0; j<g[v].size(); ++j) {
			ll to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				q.erase (make_pair (d[to], to));
				d[to] = d[v] + len;
				p[to] = v;
				q.insert (make_pair (d[to], to));
			}else if (p[to] != -1 and d[v] + len == d[to] and len < A[p[to] * 1e6 + to].second){
				q.erase (make_pair (d[to], to));
				d[to] = d[v] + len;
				p[to] = v;
				q.insert (make_pair (d[to], to));
			}
		}
	}
    ll ans = 0;
    vector<ll>R(n);
	for(ll i = 0; i < n; ++i){
        if(i == s) continue;
        ans += A[1e6 * p[i] + i].second;
        R[i] = A[1e6 * p[i] + i].first;
	}
	cout << ans;
	cout << '\n';
	for(ll i = 0; i < n; ++i){
        if(i == s)continue;
        cout << R[i] << ' ';
	}
	return 0;
}