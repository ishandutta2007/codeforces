#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int mex(vector <int> &a) {
	vector <int> exist(a.size() + 1, 0);
	for (int x : a) {
		if (x >= exist.size()) continue;
		exist[x] = 1;
	}
	for (int i = 0; ; ++i) {
		if (!exist[i]) return i;
	}
	assert(false);
}

const int M = 7;
pair <int, int> periods[M][M][M][3];
vector <int> grandi[M][M][M][3];

pair <int, int> find_period(vector <int> &a) {
	int n = a.size();
	for (int start = 0; start < a.size(); start++) {
		for (int step = 2; step <= 10; step++) {
			bool can = true;
			for (int i = start; i < a.size(); i++) {
				if (a[i] != a[start + (i - start) % step]) {
					can = false;
					break;
				}
			}
			if (can) {
				return {start, step};
			}
		}
	}
	assert(false);
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int a = 1; a <= 5; a++) {
		for (int b = 1; b <= 5; b++) {
			for (int c = 1; c <= 5; c++) {
				vector <int> powers = {a, b, c};
				int n = 100;
				vector <vector <int> > g(n + 1, vector <int> (3, 0));
				for (int i = 1; i <= n; i++) {
					for (int j = 0; j < 3; j++) {
						vector <int> moves;
						for (int now = 0; now < 3; now++) {
							if (now && now == j) continue;
							int nxt = max(i - powers[now], 0);
							moves.pb(g[nxt][now]);
						}
						g[i][j] = mex(moves);
					}
				}
				//cout << "Powers: " << a << " " << b << " " << c << endl;
				for (int t = 0; t < 3; t++) {
					vector <int> now;
					for (int i = 0; i < n; i++) {
						//cout << g[i][0] << " ";
						now.pb(g[i][t]);
					}
					periods[a][b][c][t] = find_period(now);
					grandi[a][b][c][t] = now;
					//cout << t << " " << periods[a][b][c][t].x << " " << periods[a][b][c][t].y << "\n";
					assert(periods[a][b][c][t].x < 30);
				}
			}
		}
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, x, y, z;
		cin >> n >> x >> y >> z;
		vector <int> powers = {x, y, z};
		auto per = periods[x][y][z][0];
		auto &g = grandi[x][y][z][0];
		int start = per.x, step = per.y;
		vector <int> value(n, 0);
		vector <ll> starts;
		int now_xor = 0;
		/*for (int t = 0; t < 3; t++) {
			for (int i = 0; i < 10; i++) {
				cout << grandi[x][y][z][t][i] << " ";
			}
			cout << "\n";
		}*/
		for (int i = 0; i < n; i++) {
			ll dd;
			cin >> dd;
			starts.pb(dd);
			if (dd >= start) {
				dd = (dd - start) % step + start;
			}
			value[i] = g[dd];
			now_xor ^= value[i];
			//cout << value[i] << " ";
		}
		//cout << "\n";
		//cout << "XOR: " << now_xor << "\n";
		if (!now_xor) {
			cout << "0\n";
			continue;
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int t = 0; t < 3; t++) {
				int d_xor = now_xor ^ value[i];
				ll now = max(starts[i] - powers[t], 0LL);
				//cout << now << "\n";
				auto per = periods[x][y][z][t];
				auto &g = grandi[x][y][z][t];
				int start = per.x, step = per.y;
				if (now >= start) {
					now = (now - start) % step + start;
				}
				//cout << d_xor << " " << now << " " << g[now] << "\n";
				d_xor ^= g[now];
				if (!d_xor) {
					//cout << i << " " << t << "\n";
					res++;
				}
			}
		}
		cout << res << "\n";
	}

}