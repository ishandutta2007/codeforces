#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Tree {
	int n;
	vector <int> t;
	vector <bool> flag;
	
	Tree(int n) : n(n), t(4 * n, 0), flag(4 * n, 0) {}

	void add_val(int v, bool val) {
		if (val) {
			t[v] = 0;
			flag[v] = 1;
		}
	}

	void push(int v) {
		add_val(2 * v, flag[v]);
		add_val(2 * v + 1, flag[v]);
		flag[v] = 0;
	}

	void relax(int v) {
		t[v] = t[2 * v] + t[2 * v + 1];
	}

	int get_sum(int l, int r, int vt, int lt, int rt) {
		if (l >= rt || lt >= r) {
			return 0;
		}
		if (l <= lt && rt <= r) {
			return t[vt];
		}
		push(vt);
		int mt = (lt + rt) / 2;
		int a = get_sum(l, r, 2 * vt, lt, mt);
		int b = get_sum(l, r, 2 * vt + 1, mt, rt);
		relax(vt);
		return a + b;
	}

	int get_sum(int l, int r) {
		return get_sum(l, r, 1, 0, n);
	}

	void add_seg(int l, int r, int vt, int lt, int rt) {
		if (l >= rt || lt >= r) {
			return;
		}
		if (l <= lt && rt <= r) {
			add_val(vt, 1);
			return;
		}
		push(vt);
		int mt = (lt + rt) / 2;
		add_seg(l, r, 2 * vt, lt, mt);
		add_seg(l, r, 2 * vt + 1, mt, rt);
		relax(vt);
	}

	void add_seg(int l, int r) {
		add_seg(l, r, 1, 0, n);
	}

	void add(int pos, int x, int vt, int lt, int rt) {
		if (lt > pos || rt <= pos) {
			return;
		}
		if (rt - lt == 1) {
			t[vt] += x;
			return;
		}
		push(vt);
		int mt = (lt + rt) / 2;
		add(pos, x, 2 * vt, lt, mt);
		add(pos, x, 2 * vt + 1, mt, rt);
		relax(vt);
	}

	void add(int pos, int x) {
		add(pos, x, 1, 0, n);
	}
};

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	Tree t(n);

	set <int> was;
	vector <int> st;

	vector <int> res(n, -1);

	int cnt = 0;

	for (int i = 0; i < 2 * n; ++i) {
		char c;
		cin >> c;
		if (c == '+') {
			t.add(0, 1);
			st.pb(cnt++);
		} else {
			int x;
			cin >> x;
			--x;
			int sum = t.get_sum(0, x + 1);
			if (!sum) {
				cout << "NO\n";
				return 0;
			}
			res[st.back()] = x;
			st.pop_back();
			t.add(x + 1, sum - 1);
			t.add_seg(0, x + 1);
		}
	}
	cout << "YES\n";

	for (int i = 0; i < n; ++i) {
		cout << res[i] + 1 << " ";
	}
	cout << "\n";

}