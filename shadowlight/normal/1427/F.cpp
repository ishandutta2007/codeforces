#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int N = 6 * n;

	vector <int> player(N, 1);

	for (int i = 0; i < N / 2; ++i) {
		int x;
		cin >> x;
		player[x - 1] = 0;
	}

	vector <vector <int> > cur;
	vector <int> nodes_st;

	int type = -1;

	vector <vector <int>> gr;
	vector <vector <int>> nodes;
	vector <int> p;
	vector <int> types;

	vector <int> node(N, -1);

	for (int i = 0; i < N; ++i) {
		if (cur.size() >= 1) {
			int x = cur.back()[0];
			if (player[x] != player[i]) {
				cur.pb({i});
				nodes.pb({i});
				int v = nodes.size() - 1;
				gr.pb({});
				gr[nodes_st.back()].pb(v);
				p.pb(nodes_st.back());
				types.pb(player[i]);

				nodes_st.pb(v);
				node[i] = nodes_st.back();
			} else {
				nodes[nodes_st.back()].pb(i);
				cur.back().pb(i);
				if (cur.back().size() == 3) {
					/*cout << "NEW VERTEX: " << nodes_st.back() << endl;
					for (int x : cur.back()) {
						cout << x << " ";
					}
					cout << endl;*/
					cur.pop_back();
					nodes_st.pop_back();
				}
			}
		} else {
			cur.pb({i});
			nodes.pb({i});
			int v = nodes.size() - 1;
			gr.pb({});
			p.pb(-1);
			nodes_st.pb(v);
			types.pb(player[i]);

			node[i] = nodes_st.back();
		}
	}

	int sz = nodes.size();
	vector <int> deg(sz, 0);
	vector <int> leaves;

	for (int i = 0; i < sz; ++i) {
		deg[i] = gr[i].size();
		if (!deg[i]) {
			leaves.pb(i);
		}
	}

	int turn = 0;

	//cout << gr.size() << " " << 2 * n << endl;

	for (int i = 0; i < 2 * n; ++i) {
		bool deleted = false;
		for (int i = 0; i < (int) leaves.size(); ++i) {
			int v = leaves[i];
			if (turn == types[v]) {
				if (p[v] == -1 && turn) continue;
				deleted = true;
				for (int x : nodes[v]) {
					cout << x + 1 << " ";
				}
				cout << "\n";
				leaves.erase(leaves.begin() + i);
				if (p[v] != -1) {
					--deg[p[v]];
					if (!deg[p[v]]) {
						leaves.pb(p[v]);
					}
				}
				break;
			}
		}
		if (turn && !deleted) {
			for (int i = 0; i < (int) leaves.size(); ++i) {
				int v = leaves[i];
				if (turn == types[v]) {
					deleted = true;
					for (int x : nodes[v]) {
						cout << x + 1 << " ";
					}
					cout << "\n";
					leaves.erase(leaves.begin() + i);
					break;
				}
			}
		}
		turn ^= 1;
	}

}