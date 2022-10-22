#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;

int n;
vector <int> a;

vector <vector <pair <ll, int> > > qs;
vector <int> res;
vector <int> used;

vector <vector <int> > gr;

vector <int> dfs(int v) {
	vector <int> mas(1, 1);
	for (int u : gr[v]) {
		auto upd = dfs(u);
		upd.push_back(0);
		if (upd.size() > mas.size()) swap(upd, mas);
		for (int i = 0; i < (int) upd.size(); i++) {
			mas[(int) mas.size() - 1 - i] += upd[(int) upd.size() - 1 - i];
		}
	}

	if (used[v] == 1) {
		for (auto t : qs[v]) {
			ll x = t.first;
			//cout << x << " " << t.second << "\n";
			if (x >= (int) mas.size()) {
				res[t.second] = 0;
			} else {
				res[t.second] = mas[(int) mas.size() - 1 - x]; 
			}
		}
	}
	return mas;
}

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	a.resize(n);
	gr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	vector <vector <int> > cycles;
	vector <int> pos(n, -1), num(n, -1);

	used.resize(n, 0);

	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		vector <int> mas;
		int v = i;
		while (!used[v]) {
			used[v] = 1;
			mas.push_back(v);
			v = a[v];
		}
		vector <int> cycle;
		while (mas.size() && mas.back() != v) {
			cycle.push_back(mas.back());
			mas.pop_back();
		}
		if (!mas.size()) {
			continue;
		}
		cycle.push_back(mas.back());

		reverse(cycle.begin(), cycle.end());
		cycles.push_back(cycle);


		for (int t = 0; t < (int) cycle.size(); t++) {
			int v = cycle[t];
			used[v] = 2;	
			num[v] = cycles.size() - 1;
			pos[v] = t;
		}
	}

	int q;
	cin >> q;

	res.resize(q);
	qs.resize(n);

	for (int i = 0; i < q; i++) {
		ll m;
		cin >> m;
		int v;
		cin >> v;
		v--;
		if (used[v] == 1) {
			qs[v].push_back({m, i});
		} else {
			auto &cycle = cycles[num[v]];
			int post = pos[v];
			int sz = cycle.size();
			int now_sh = m % sz;
			int pos = (post - now_sh + sz) % sz;
			int nxt = cycle[pos];
			qs[nxt].push_back({m, i});
		}
	}

	/*cout << cycles.size() << "\n";
	for (auto cycle : cycles) {
		cout << cycle.size() << " ";
	}
	cout << "\n";
	exit(0);*/


	for (int i = 0; i < n; i++) {
		if (used[i] == 1) {
			gr[a[i]].push_back(i);
		}
	}

	vector <vector <pair <int, int> > > cnts(n);

	for (int i = 0; i < n; i++) {
		if (used[i] == 2) {
			auto t = dfs(i);
			auto &cycle = cycles[num[i]];
			int post = pos[i];
			int sz = cycle.size();
			for (int dist = 0; dist < (int) t.size(); dist++) {
				int cnt = t[(int) t.size() - 1 - dist];
				int now_sh = dist % sz;
				int pos = (post - now_sh + sz) % sz;
				int nxt = cycle[pos];
				int now_dist = dist - dist % sz;
				if (dist % sz) {
					now_dist += sz;
				}
				cnts[nxt].push_back({dist, cnt});
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (used[i] == 2) {
			sort(cnts[i].begin(), cnts[i].end());
			auto pref = cnts[i];
			for (int i = 1; i < (int) pref.size(); i++) {
				pref[i].second += pref[i - 1].second;
			}
		/*	cout << i << "\n";
			for (auto t : pref) {
				cout << t.first << " " << t.second << "\n";
			}
			cout << "---\n";*/
			for (auto qt : qs[i]) {
				ll x = qt.first, id = qt.second;
				int pos = lower_bound(pref.begin(), pref.end(), make_pair((x > INF ? INF : (int) x), INF)) - pref.begin();
				res[id] = pref[pos - 1].second;
			}
		}
	}

	for (int i = 0; i < q; i++) {
		cout << res[i] << "\n";
	}
}