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
	vector <int> mink;
	vector <ll> sum;
	vector <int> val;

	void add_val(int x, int vt, int lt, int rt) {
		if (x != -1) {
			sum[vt] = (rt - lt) * (ll) x; 
			mink[vt] = x;
			val[vt] = max(val[vt], x);
		}
	}

	void push(int vt, int lt, int rt) {
		int mt = (lt + rt) / 2;
		add_val(val[vt], 2 * vt, lt, mt);	
		add_val(val[vt], 2 * vt + 1, mt, rt);	
		val[vt] = -1;
	}

	void relax(int vt) {
		sum[vt] = sum[2 * vt] + sum[2 * vt + 1];
		mink[vt] = mink[2 * vt + 1];
	}

	void build(int v, int l, int r, vector<int>& a) {
		if (r - l == 1) {
			add_val(a[l], v, l, r);
			return;
		}
		int m = (l + r) / 2;
		build(2 * v, l, m, a);
		build(2 * v + 1, m, r, a);
		relax(v);
	}

	Tree(int n, vector<int>& a) : n(n), mink(4 * n), sum(4 * n, 0), val(4 * n, -1) {
		build(1, 0, n, a);
	}

	int get_less_pos(int x, int vt, int lt, int rt) {
		if (rt - lt == 1) {
			if (mink[vt] > x) {
				return n;
			}
			return lt;
		}
		push(vt, lt, rt);
		int mt = (lt + rt) / 2;
		int ret;
		//cout << "LESS: " << x << " " << lt << " " << rt << "\n";
		if (mink[2 * vt] <= x) {
			ret = get_less_pos(x, 2 * vt, lt, mt);
		} else {
			ret = get_less_pos(x, 2 * vt + 1, mt, rt);
		}
		relax(vt);
		return ret;
	}

	int get_less_pos(int x) {
		return get_less_pos(x, 1, 0, n);
	}

	pair <int, int> get_less_sum(int l, int x, int vt, int lt, int rt) {
		if (l >= rt) {
			return {0, 0};
		}
		//cout << "NOW: " << lt << " " << rt << "\n";
		//cout << lt << " " << l << "\n";
		if (rt - lt == 1) {
			//cout << "KEKW: " << lt << " " << rt << " " << sum[vt] << "\n";
			if (sum[vt] <= x) {
				return {sum[vt], 1};
			}
			return {0, 0};
		}
		push(vt, lt, rt);
		int mt = (lt + rt) / 2;
		if (lt >= l) {
			if (sum[2 * vt] <= x) {
				auto t = get_less_sum(l, x - sum[2 * vt], 2 * vt + 1, mt, rt);
				relax(vt);
				return {sum[2 * vt] + t.x, (mt - lt) + t.y};
			} else {
				auto t = get_less_sum(l, x, 2 * vt, lt, mt);
				relax(vt);
				return t;
			}
		} else {
			auto t = get_less_sum(l, x, 2 * vt, lt, mt);
			pair <int, int> tt = {0, 0};
			//cout << "AHAHA: " << lt << " " << rt << " " << t.y << " " << mt - max(lt, l) << "\n";
			if (t.y >= mt - max(lt, l)) {
				tt = get_less_sum(l, x - t.x, 2 * vt + 1, mt, rt);
			}
			relax(vt);
			return {t.x + tt.x, t.y + tt.y};
		}
	}

	pair <int, int> get_less_sum(int l, int x) {
		return get_less_sum(l, x, 1, 0, n);
	}

	void add_seg(int l, int r, int x, int vt, int lt, int rt) {
		if (lt >= r || l >= rt) {
			return;
		}
		if (l <= lt && rt <= r) {
			add_val(x, vt, lt, rt);
			return;
		}
		push(vt, lt, rt);
		int mt = (lt + rt) / 2;
		add_seg(l, r, x, 2 * vt, lt, mt);
		add_seg(l, r, x, 2 * vt + 1, mt, rt);
		relax(vt);
	}

	void add_seg(int l, int r, int x) {
		add_seg(l, r, x, 1, 0, n);
	}

	ll get_sum(int l, int r, int vt, int lt, int rt) {
		if (l >= rt || lt >= r) {
			return 0;
		}
		if (l <= lt && rt <= r) {
			return sum[vt];
		}
		push(vt, lt, rt);
		int mt = (lt + rt) / 2;
		ll x = get_sum(l, r, 2 * vt, lt, mt);
		ll y = get_sum(l, r, 2 * vt + 1, mt, rt);
		relax(vt);
		return x + y;
	}

	ll get_sum(int l, int r) {
		return get_sum(l, r, 1, 0, n);
	}
};

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	Tree tree(n, a);

	for (int i = 0; i < q; ++i) {
		int tp, x, y;
		cin >> tp >> x >> y;
		--x;
		if (tp == 1) {
			int pos = tree.get_less_pos(y);
			tree.add_seg(pos, x + 1, y);
			//cout << "ASSIGN: " << pos << " " << x + 1 << " " << y << "\n";
		} else {
			int res = 0;
			while (true) {
				int pos = max(tree.get_less_pos(y), x);
				//cout << "FIND: " << x << " " << tree.get_less_pos(y) << " " << y << "\n";
				auto t = tree.get_less_sum(pos, y);
				//cout << t.x << " " << t.y << " " << y << "\n";
				//cout << "SEG: " << pos << " " << pos + t.y - 1 << "\n";
				if (!t.y) {
					break;
				}
				res += t.y;
				y -= t.x;
				x = pos + t.y;
			}
			cout << res << "\n";
		}
	}

}