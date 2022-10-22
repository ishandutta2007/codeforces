#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

const int MAXN = 1e6 + 7;
const int INF = 1e9 + 7;

pair <ll, int> t[4 * MAXN];
ll add[4 * MAXN];

int sz;

void relax(int v) {
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

void add_val(int v, ll val) {
	add[v] += val;
	t[v].first += val;
}

void push(int v) {
	add_val(2 * v, add[v]);
	add_val(2 * v + 1, add[v]);
	add[v] = 0;
}

void add_seg(int l, int r, int val, int vt = 1, int lt = 0, int rt = sz) {
	if (lt >= r || l >= rt) {
		return;
	}
	if (l <= lt && rt <= r) {
		add_val(vt, val);
		return;
	}
	push(vt);
	int mt = (lt + rt) / 2;
	add_seg(l, r, val, 2 * vt, lt, mt);
	add_seg(l, r, val, 2 * vt + 1, mt, rt);
	relax(vt);
}

void change(int pos, int x, int vt = 1, int lt = 0, int rt = sz) {
	if (lt > pos || rt <= pos) {
		return;
	}
	if (rt - lt == 1) {
		t[vt] = {x, pos};
		return;
	}
	push(vt);
	int mt = (lt + rt) / 2;
	change(pos, x, 2 * vt, lt, mt);
	change(pos, x, 2 * vt + 1, mt, rt);
	relax(vt);
}

struct Data {
	int x, y, c;
};

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> c(n), xs(n), ys(n);
	map <int, vector <Data> > idx;
	set <int> aid;
	map <int, int> nx;
	vector <int> sx;
	for (int i = 0; i < n; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		aid.insert(max(x, y));
		idx[min(x, y)].push_back({x, y, c});
	}
	int now = 0;
	for (auto &t : aid) {
		nx[t] = now++;
		sx.push_back(t);
	}
	sz = sx.size();
	ll res = 0;
	for (int i = 0; i < sz; i++) {
		change(i, -sx[i]);
	}

	vector <int> order;
	for (auto &t : idx) {
		order.push_back(t.first);
	}

	int resa = INF, resb = INF;

	reverse(order.begin(), order.end());
	int wasa = INF;
	for (int a : order) {
		int pos_r = lower_bound(sx.begin(), sx.end(), wasa) - sx.begin();
		int pos_l = lower_bound(sx.begin(), sx.end(), a) - sx.begin();
		add_seg(pos_r, sz, a - wasa);
		add_seg(pos_l, pos_r, a);
		for (auto t : idx[a]) {
			int mb = max(t.x, t.y);
			int pos = lower_bound(sx.begin(), sx.end(), mb) - sx.begin();
			add_seg(pos, sz, t.c);
		}
		if (res < t[1].first) {
			res = t[1].first;
			resa = a;
			resb = sx[t[1].second];
		}
		wasa = a;
	}
	cout << res << "\n";
	cout << resa << " " << resa << " " << resb << " " << resb << "\n";
}