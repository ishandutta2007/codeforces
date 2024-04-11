#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

const int MXP = 4e7;
bitset<MXP> prime;
vector<ll> primes;

void sieve() {
	for(int p = 2; p < MXP; p++) {
		if(prime[p])
			continue;
		primes.push_back(p);
		for(int q = p; q < MXP; q += p)
			prime.set(q);
	}
}

map<ll, vector<pair<ll, int>>> qry;
bool ans[10005];
vector<ii> adj[100005];
ll dis[100005];

ll euclid(ll a, ll b, ll &x, ll &y) {
	if(b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

void solve(ll k, vector<pair<ll, int>> &qs) {
	if(k == 1) {
		for(auto q : qs)
			ans[q.second] = false;
		return;
	}
	vector<ll> pf;
	for(auto p : primes) {
		if(p*p > k)
			break;
		if(k % p)
			continue;
		pf.push_back(p);
		while(k % p == 0)
			k /= p;
	}
	if(k > 1)
		pf.push_back(k);
	sort(pf.begin(), pf.end());
	if(pf.size() == 1) {
		for(auto q : qs)
			ans[q.second] = (q.first % pf[0] == 0);
		return;
	}
	if(pf.size() == 2) {
		ll x, y;
		ll p = pf[0], q = pf[1];
		euclid(q, p, x, y);
		// qx + py = 1
		// qx = 1 mod p
		// qnx = n mod p
		x = (x%p + p) % p;
		for(auto qry : qs) {
			ll n = qry.first;
			ll d = n % p;
			ll fi = ((n%p) * x)%p;
			ans[qry.second] = (q * fi <= n);
		}
		return;
	}
	for(int i = 0; i < pf[0]; i++) {
		adj[i].clear();
		for(int j = 1; j < pf.size(); j++) {
			ll p = pf[j];
			adj[i].push_back({(i + p)%pf[0], p});
		}
	}
	fill(dis, dis + pf[0], LLONG_MAX);
	priority_queue<ii, vector<ii>, greater<ii>> q;
	dis[0] = 0;
	q.push({0, 0});
	while(!q.empty()) {
		ll d = q.top().first, u = q.top().second; q.pop();
		if(d > dis[u])
			continue;
		for(auto e : adj[u]) {
			ll v = e.first, w = e.second;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
	for(auto q : qs)
		ans[q.second] = (dis[q.first % pf[0]] <= q.first);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		ll n, k;
		cin >> n >> k;
		qry[k].push_back({n, i});
	}
	for(auto p : qry)
		solve(p.first, p.second);
	for(int i = 0; i < t; i++)
		cout << (ans[i] ? "YES\n" : "NO\n");
}