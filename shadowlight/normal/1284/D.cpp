#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1e6 + 7;

struct Rect {
	int a, b, c, d;
};

struct Tree {

	ll t[4 * N], vals[4 * N];

	void relax(int vt) {
		t[vt] = t[2 * vt] + t[2 * vt + 1];
	}

	void add_val(int vt, int lt, int rt, ll x) {
		t[vt] += (rt - lt) * (ll) x;
		vals[vt] += x;
	}

	void push(int vt, int lt, int rt) {
		int mt = (lt + rt) / 2;
		add_val(2 * vt, lt, mt, vals[vt]);
		add_val(2 * vt + 1, mt, rt, vals[vt]);
		vals[vt] = 0;
	}

	void add(int l, int r, int x, int vt = 1, int lt = 0, int rt = N) {
		if (lt >= r || l >= rt) {
			return;
		}
		if (l <= lt && rt <= r) {
			add_val(vt, lt, rt, x);
			return;
		}
		int mt = (lt + rt) / 2;
		push(vt, lt, rt);
		add(l, r, x, 2 * vt, lt, mt);
		add(l, r, x, 2 * vt + 1, mt, rt);
		relax(vt);
	}

	ll get(int l, int r, int vt = 1, int lt = 0, int rt = N) {
		if (l >= rt || lt >= r) {
			return 0;
		}
		if (l <= lt && rt <= r) {
			return t[vt];
		}
		int mt = (lt + rt) / 2;
		push(vt, lt, rt);
		ll res = get(l, r, 2 * vt, lt, mt);
		res += get(l, r, 2 * vt + 1, mt, rt);
		relax(vt);
		return res;
	}

};

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <Rect> rect;
	set <int> vals;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		rect.push_back({a, b, c, d});
		vals.insert(a);
		vals.insert(b);
		vals.insert(c);
		vals.insert(d);
	}
	int now = 0;
	map <int, int> nval;
	for (int x : vals) {
		nval[x] = now++;
	}
	for (int i = 0; i < n; i++) {
		rect[i].a = nval[rect[i].a];
		rect[i].b = nval[rect[i].b];
		rect[i].c = nval[rect[i].c];
		rect[i].d = nval[rect[i].d];
	}
	for (int tt = 0; tt < 2; tt++) {
		Tree tree;
		vector <int> a, b;
		for (int i = 0; i < n; i++) {
			a.push_back(i), b.push_back(i);
		}
		sort(a.begin(), a.end(), [&] (int i, int j) {
			return rect[i].a < rect[j].a;
		});
		sort(b.begin(), b.end(), [&] (int i, int j) {
			return rect[i].b < rect[j].b;
		});
		for (int x : a) {
			int l = rect[x].c, r = rect[x].d;
			tree.add(l, r + 1, 1);
		}
		int it = 0;
		for (int x : b) {
			while (it < n && rect[a[it]].a <= rect[x].b) {
				int l = rect[a[it]].c, r = rect[a[it]].d;
				tree.add(l, r + 1, -1);
				it++;
			} 
			if (it != n) {
				int l = rect[x].c, r = rect[x].d;
				ll val = tree.get(l, r + 1);
				if (val) {
					cout << "NO\n";
					return 0;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			swap(rect[i].a, rect[i].c);
			swap(rect[i].b, rect[i].d);
		}
	}
	cout << "YES\n";
}