#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const int INF = 1e9 + 7;
const int N = 2e5 + 7;
int nearest[N][4];
int from[N][4];

int n, qq, s, d;
vector <int> res;
vector <int> a;

set <pair<int, int>> q;
set <int> alive;

void update_edge(int v, int to, int t) {
	nearest[v][t] = to;
	if (to == -1) return;
	int d1 = (from[to][t] == -1 ? INF : a[from[to][t]]);
	int d2 = a[v];

	d1 = abs(d - abs(d1 - a[to]));
	d2 = abs(d - abs(d2 - a[to]));

	//cout << v << " " << to << " " << d1 << " " << d2 << endl;

	if (d1 > d2) {
		from[to][t] = v;
	}
	if (res[to] == -1 || res[to] > max(d2, res[v])) {
		q.erase({res[to], to});
		res[to] = max(d2, res[v]);
		q.insert({res[to], to});
	}
}

void update(int v) {
	alive.erase(v);

	for (int t = 0; t < 4; ++t) {
		int u = from[v][t];
		if (u == -1) continue;

		int index = v;
		if (alive.find(index) == alive.end()) {
			auto it = alive.lower_bound(index);
			index = -1;
			if ((t & 1) && it != alive.begin()) {
				index = *(--it);
			} else if (!(t & 1) && it != alive.end()) {
				index = *it;
			}
			if (index != -1) {
				if (t & 2) {
					if (index < u) {
						index = -1;
					}
				} else {
					if (index > u) {
						index = -1;
					}
				}
			}
		}
		//cout << u << " " << res[u] << " " << index << " " << t << endl;
		update_edge(u, index, t);
	}

	for (int t = 0; t < 4; ++t) {
		int val = a[v] + d * (t & 2 ? 1 : -1);
		int index = lower_bound(all(a), val) - a.begin() - (t & 1);
		if (alive.find(index) == alive.end()) {
			auto it = alive.lower_bound(index);
			index = -1;
			if ((t & 1) && it != alive.begin()) {
				index = *(--it);
			} else if (!(t & 1) && it != alive.end()) {
				index = *it;
			}
			if (index != -1) {
				if (t & 2) {
					if (index < v) {
						index = -1;
					}
				} else {
					if (index > v) {
						index = -1;
					}
				}
			}
		}
		update_edge(v, index, t);
	}
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> qq >> s >> d;
	--s;

	for (int i = 0; i < n; ++i) {
		alive.insert(i);
		for (int j = 0; j < 4; ++j) {
			nearest[i][j] = -1;
			from[i][j] = -1;
		}
	}

	res.resize(n, -1);
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	res[s] = 0;
	q.insert({res[s], s});
	while (!q.empty()) {
		int v = q.begin()->y;
		q.erase(q.begin());
		update(v);
	}

	/*for (int i = 0; i < n; ++i) {
		cout << res[i] << " ";
	}
	cout << endl;*/

	for (int i = 0; i < qq; ++i) {
		int pos, k;
		cin >> pos >> k;
		--pos;
		if (k >= res[pos]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}