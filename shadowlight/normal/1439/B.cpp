#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <vector<int>> gr;

const int SZ = 22;
struct HashTable{
    ll was[(1 << SZ) + 7];
    int val[(1 << SZ) + 7];

    HashTable() { for (int i = 0; i < (1 << SZ) + 7; i++) was[i] = -1; }

    vector<int> tt;

    void clear(){
    	for (int x : tt) {
    		was[x] = -1;
    	}
    	tt.clear();
    }

    void set(ll pos, int new_val){
        int gg = ((1 << SZ) - 1) & pos;
        int p = (gg * (ll)gg * 3 + gg * 7 + 11) & ((1 << SZ) - 1);
        while(1){
            if (was[p] == -1){
                was[p] = pos;
                val[p] = new_val;
                tt.pb(p);
                return;
            } else if (was[p] == pos) {
                val[p] = new_val;
                return;
            }
            p++;
            if (p == (1 << SZ)) p = 0;
        }
    }

    int get(ll pos){
        int gg = ((1 << SZ) - 1) & pos;
        int p = (gg * (ll)gg * 3 + gg * 7 + 11) & ((1 << SZ) - 1);
        while(1){
            if (was[p] == -1){
                return 0;
            } else if (was[p] == pos) {
                return val[p];
            }
            p++;
            if (p == (1 << SZ)) p = 0;
        }
    }
} edges;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	gr.clear();
	gr.resize(n);

	set <pair <int, int>> q;
	vector <int> degs(n, 0);

	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		if (v > u) swap(v, u);
		edges.set(n * v + u, 1);

		gr[v].pb(u);
		gr[u].pb(v);
	}

	if (k * (ll) (k - 1) / 2 > m) {
		cout << "-1\n";
		return;
	}

	for (int i = 0; i < n; ++i) {
		degs[i] = gr[i].size();
		q.insert({gr[i].size(), i});
	}

	vector <int> deleted(n, false);

	while (q.size()) {
		int v = q.begin()->y;
		int cnt = q.begin()->x;

		if (cnt == k - 1) {
			vector <int> vs = {v};
			for (int u : gr[v]) {
				if (deleted[u]) continue;
				vs.pb(u);
			}
			bool is_clique = true;
			for (int i = 0; i < (int) vs.size(); ++i) {
				for (int j = i + 1; j < (int) vs.size(); ++j) {
					int v = vs[i], u = vs[j];
					if (v > u) swap(v, u);
					if (!edges.get(v * n + u)) {
						is_clique = false;
						break;
					}	
				}
			}
			if (is_clique) {
				cout << 2 << "\n";
				for (int x : vs) {
					cout << x + 1 << " ";
				}
				cout << "\n";
				edges.clear();
				return;
			}
		}

		if (cnt <= k - 1) {
			q.erase(q.begin());
			deleted[v] = true;
			for (int u : gr[v]) {
				if (deleted[u]) continue;
				
				q.erase({degs[u], u});
				--degs[u];
				q.insert({degs[u], u});
			}
			continue;
		}
		if (cnt > k - 1) {
			cout << 1 << " " << q.size() << "\n";
			for (auto t : q) {
				cout << t.y + 1 << " ";
			}
			cout << "\n";
			return;
		}

	}
	cout << "-1\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
		edges.clear();
	}

}