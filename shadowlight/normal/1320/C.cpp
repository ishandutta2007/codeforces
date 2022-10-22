#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1e6 + 7;
const int INF = 2e9 + 7;

int t[4 * N], val[4 * N];

void relax(int v) {
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

void add_val(int v, int valt) {
	val[v] += valt;
	t[v] += valt;
}

void push(int v) {
	add_val(2 * v, val[v]);
	add_val(2 * v + 1, val[v]);
	val[v] = 0;
}

void add_seg(int l, int r, int valt, int lt = 0, int rt = N, int vt = 1) {
	if (l >= rt || lt >= r) {
		return;
	}
	if (l <= lt && rt <= r) {
		add_val(vt, valt);
		return;
	}
	push(vt);
	int mt = (lt + rt) / 2;
	add_seg(l, r, valt, lt, mt, 2 * vt);
	add_seg(l, r, valt, mt, rt, 2 * vt + 1);
	relax(vt);
}

int get(int l, int r, int lt = 0, int rt = N, int vt = 1) {
	if (l >= rt || lt >= r) {
		return -INF;
	}
	if (l <= lt && rt <= r) {
		return t[vt];
	}
	push(vt);
	int mt = (lt + rt) / 2;
	int res = max(get(l, r, lt, mt, 2 * vt), get(l, r, mt, rt, 2 * vt + 1));
	relax(vt);
	return res;
}

struct Data {
	int x, y, z;
};

signed main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, p;
	cin >> n >> m >> p;

	vector <pair <int, int> > as(n), bs(m);

	for (int i = 0; i < n; i++) {
		cin >> as[i].x >> as[i].y;
	}

	for (int i = 0; i < m; i++) {
		cin >> bs[i].x >> bs[i].y;
	}

	sort(as.rbegin(), as.rend());
	sort(bs.rbegin(), bs.rend());

	vector <Data> data(p);
	for (int i = 0; i < p; i++) {
		cin >> data[i].x >> data[i].y >> data[i].z;
	}
	sort(data.begin(), data.end(), [&](Data a, Data b) {
		return a.x > b.x;
	});

	int iter = 0;
	int it2 = 0;
	int min_val = INF;
	for (int i = N - 1; i >= 0; i--) {
		while (iter < bs.size() && bs[iter].x == i) {
			min_val = min(min_val, bs[iter].y);
			iter++;
		}
		while (it2 < data.size() && data[it2].x == i) {
			add_seg(data[it2].y + 1, N, data[it2].z);
			it2++;
		}
		add_seg(i, i + 1, -min_val);
		//if (i < 12) cout << i << " " << -min_val << "\n";
	}

	iter = 0;
	it2 = 0;
	min_val = INF;

	int res = -INF;

	for (int i = N - 1; i >= 0; i--) {
		while (iter < as.size() && as[iter].x == i) {
			min_val = min(min_val, as[iter].y);
			iter++;
		}
		while (it2 < data.size() && data[it2].x == i) {
			add_seg(data[it2].y + 1, N, -data[it2].z);
			it2++;
		}
		res = max(res, get(0, N) - min_val);
	}
	cout << res << "\n";
}