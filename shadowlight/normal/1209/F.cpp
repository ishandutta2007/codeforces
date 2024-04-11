#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int LOGN = 20;
const int Q = 31;
const int N = 2e5 + 7;

vector <vector <pair <int, int> > > gr;
vector <pair <int, int> > res;
vector <int> hsh;
vector <vector <pair <int, int> > > binup;

vector <int> geta(int x) {
	vector <int> res;
	while (x) {
		res.push_back(x % 10);
		x /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int n, m;
	cin >> n >> m;
	int sz = n;
	gr.resize(n);

	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		auto tv = geta(i + 1), tu = geta(i + 1);
		int last = v;
		for (int i = 0; i < (int) tu.size() - 1; i++) {
			gr.push_back({});
			sz++;
			gr[last].push_back({sz - 1, tu[i]});
			last = sz - 1;
		}
		gr[last].push_back({u, tu.back()});
	
		last = u;
		for (int i = 0; i < (int) tv.size() - 1; i++) {
			gr.push_back({});
			sz++;
			gr[last].push_back({sz - 1, tv[i]});
			last = sz - 1;
		}
		gr[last].push_back({v, tv.back()});
	}

	res.resize(sz, {MOD, MOD});
	hsh.resize(sz, -1);
	binup.resize(sz, vector <pair <int, int> > (LOGN, {-1, -1}));
	set <pair <pair <int, int> , int> > q;
	res[0] = {0, 0};
	hsh[0] = 0;
	q.insert({res[0], 0});
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());
		for (auto e : gr[v]) {
			int u = e.first, w = e.second;
			if (res[u].first < res[v].first + 1) continue;

			if (res[u].first > res[v].first + 1) {
				q.erase({res[u], u});
				res[u] = res[v];
				res[u].first += 1;
				res[u].second = (res[u].second * (ll) 10 + w) % MOD;
				hsh[u] = (hsh[v] * (ll) 31 + w) % MOD2;
				binup[u][0] = {v, w};
				for (int t = 1; t < LOGN; t++) {
					if (binup[u][t - 1].first == -1) break; 
					binup[u][t] = binup[binup[u][t - 1].first][t - 1];
				}
				q.insert({res[u], u});
				continue;
			}

			bool can_upd = false;

			auto last_e = binup[u][0];
			int nv = v, nu = last_e.first;

			if (hsh[nv] == hsh[nu] && res[nv].second == res[nu].second) {
				can_upd = (last_e.second > w);
			} else {
				for (int t = LOGN - 1; t >= 0; t--) {
					int du = binup[nu][t].first, dv = binup[nv][t].first;
					if (dv == -1) continue;
					if (hsh[dv] == hsh[du] && res[du].second == res[dv].second) continue;
					nv = dv;
					nu = du;
				}
				int sv = binup[nv][0].second, su = binup[nu][0].second;
				can_upd = (su > sv);
			}
			if (can_upd) {
				q.erase({res[u], u});
				res[u] = res[v];
				res[u].first += 1;
				res[u].second = (res[u].second * (ll) 10 + w) % MOD;
				hsh[u] = (hsh[v] * (ll) 31 + w) % MOD2;
				binup[u][0] = {v, w};
				for (int t = 1; t < LOGN; t++) {
					if (binup[u][t - 1].first == -1) break; 
					binup[u][t] = binup[binup[u][t - 1].first][t - 1];
				}
				q.insert({res[u], u});
			}

		}
	}
	for (int i = 1; i < n; i++) {
		cout << res[i].second << "\n";
	}
}