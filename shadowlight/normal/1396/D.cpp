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

struct Tree {
	int n;
	vector<ll> t;
	vector <int> mx;
	vector<int> val;
	vector <int> weights;

	void add_val(int v, int l, int r, int now) {
		t[v] = weights[v] * (ll) now;
		mx[v] = now;
		val[v] = now;
	}
	
	void push(int v, int l, int r) {
		if (val[v] == -1) return;
		int m = (l + r) / 2;
		add_val(2 * v, l, m, val[v]);
		add_val(2 * v + 1, m, r, val[v]);
		val[v] = -1;
	}

	void relax(int v) {
		t[v] = t[2 * v] + t[2 * v + 1];
		mx[v] = max(mx[2 * v], mx[2 * v + 1]);
		weights[v] = weights[2 * v] + weights[2 * v + 1];
	}
	void build(vector <int>& a, vector <int>& w, int v, int l, int r) {
		if (r - l == 1) {
			t[v] = a[l] * (ll) w[l];
			mx[v] = a[l];
			weights[v] = w[l];
			return;
		}
		int m = (l + r) / 2;
		build(a, w, 2 * v, l, m);
		build(a, w, 2 * v + 1, m, r);
		relax(v);
	}
	
	Tree(vector <int>& a, vector <int>& w) : n(a.size()), t(4 * n), val(4 * n, -1), weights(4 * n), mx(4 * n) {
		build(a, w, 1, 0, n);
	}

	ll get_sum(int l, int r, int vt, int lt, int rt) {
		if (l >= rt || lt >= r) {
			return 0;
		}
		if (l <= lt && rt <= r) {
			return t[vt];
		}
		push(vt, lt, rt);
		int mt = (lt + rt) / 2;
		auto x = get_sum(l, r, 2 * vt, lt, mt);
		auto y = get_sum(l, r, 2 * vt + 1, mt, rt);
		relax(vt);
		return x + y;
	}

	ll get_sum(int l, int r) {
		return get_sum(l, r, 1, 0, n);
	}

	void change_max(int l, int r, int now, int vt, int lt, int rt) {
		if (l >= rt || lt >= r) {
			return;
		}
		int mt = (lt + rt) / 2;
		if (l <= lt && rt <= r) {
			if (mx[vt] < now) {
				add_val(vt, lt, rt, now);
				return;
			}
			if (rt - lt == 1) return;
			push(vt, lt, rt);
			if (mx[2 * vt] < now) {
				add_val(2 * vt, lt, mt, now);
				change_max(l, r, now, 2 * vt + 1, mt, rt);
			} else {
				change_max(l, r, now, 2 * vt, lt, mt);
			}
			relax(vt);
			return;
		}
		push(vt, lt, rt);
		change_max(l, r, now, 2 * vt, lt, mt);
		change_max(l, r, now, 2 * vt + 1, mt, rt);
		relax(vt);
	}

	void change_max(int l, int r, int now) {
		change_max(l, r, now, 1, 0, n);
	}

	int get_pos(int val, int vt, int lt, int rt) {
		if (rt - lt == 1) {
			return (t[vt] >= val ? lt : -1);
		}
		push(vt, lt, rt);
		int mt = (lt + rt) / 2;

		if (mx[2 * vt] >= val) {
			return get_pos(val, 2 * vt, lt, mt);
		}
		return get_pos(val, 2 * vt + 1, mt, rt);
	}

	int get_pos(int val) {
		return get_pos(val, 1, 0, n);
	}

	void print(int vt, int lt, int rt) {
		if (rt - lt == 1) {
			cout << mx[vt] << " ";
			return;
		}
		push(vt, lt, rt);
		int mt = (lt + rt) / 2;
		print(2 * vt, lt, mt);
		print(2 * vt + 1, mt, rt);
		relax(vt);
	}

	void print() {
		cout << "FXS\n";
		print(1, 0, n);
		cout << "\n";
	}
};

void add(int& x, int y) {
	x += y;
	if (x >= INF) {
		x -= INF;
	}
	if (x < 0) {
		x += INF;
	}
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, L;
	cin >> n >> k >> L;

	set <int> xs;
	set <int> ys;

	vector <int> color(n);

	vector <pair <int, int> > points(n);
	map <int, vector <int>> ymp;

	for (int i = 0; i < n; ++i) {
		int c, x, y;
		cin >> x >> y >> c;
		--c;
		color[i] = c;
		points[i] = {x, y};
		ymp[y].pb(i);
		xs.insert(x);
		ys.insert(y);
	}
	ys.insert(L);
	map <int, int> nx;
	vector <int> xval;
	int now = 0;
	for (int x : xs) {
		nx[x] = now++;
		xval.pb(x);
	}

	int res = 0;

	vector <pair <int, int> > xcur;
	vector <multiset <int>> allx(k);
	int y_prev = 0;
	for (int y_up : ys) {
		//cout << "##############################################################\n";
		vector <int> fx;
		vector <int> lens;
		
		map <int, int> posq;

		int pr = 0;
		for (auto t : xcur) {
			lens.pb(xval[t.x] - pr + 1);
			
			posq[t.x] = lens.size() - 1;

			pr = xval[t.x] + 1;
		}
		lens.pb(L - pr);
		
		vector <int> color_count(k, 0);
		int exist_colors = 0;
		int rt = 0;
		while (rt < (int) xcur.size() && exist_colors < k) {
			int c = xcur[rt].y;
			++color_count[c];
			exist_colors += (color_count[c] == 1);
			++rt;
		}
		if (exist_colors == k) {
			fx.pb(xval[xcur[rt - 1].x]);
		}
		for (int lt = 0; lt < (int) xcur.size(); ++lt) {
			int c = xcur[lt].y;
			--color_count[c];
			exist_colors -= (color_count[c] == 0);
			while (rt < (int) xcur.size() && exist_colors < k) {
				int c = xcur[rt].y;
				++color_count[c];
				exist_colors += (color_count[c] == 1);
				++rt;
			}
			if (exist_colors == k) {
				fx.pb(xval[xcur[rt - 1].x]);
			} else break;
		}

		while (fx.size() < lens.size()) {
			fx.pb(L);
		}

		/*cout << y_up << " " << fx.size() << " " << lens.size() << endl;

		for (int x : fx) {
			cout << x << " ";
		}
		cout << endl;

		for (int x : lens) {
			cout << x << " ";
		}
		cout << endl;*/

		Tree tree(fx, lens);
		pr = 0;
		for (int y_down : ys) {
			if (y_down == y_up) break;
			int dy = y_down - pr + 1;
			int ddy = y_up - y_prev;
			//cout << (L * (ll) L - tree.get_sum(0, fx.size())) << " " << tree.get_sum(0, fx.size()) << endl;
			add(res, ddy * (ll)dy % INF * ((L * (ll) L - tree.get_sum(0, fx.size())) % INF) % INF);

			/*tree.print();
			for (auto x : lens) {
				cout << x << " ";
			}
			cout << endl;

			cout << "VALS: " << y_down << " " << res  << " " << ddy << " " << dy << " " << L * L << " " << tree.get_sum(0, fx.size()) << endl;

			cout << "================\n";*/

			for (auto ind : ymp[y_down]) {
				int x = nx[points[ind].x];
				int c = color[ind];
				allx[c].erase(allx[c].find(x));
			}
			vector <pair <int, pair <int, int>>> queries;
			for (auto ind : ymp[y_down]) {
				int x = nx[points[ind].x];
				int c = color[ind];
				int x_ind = upper_bound(all(xcur), mp(x, INF)) - xcur.begin() - 1;

				auto it = allx[c].lower_bound(x);
				int prv = 0, nxt;
				if (it != allx[c].end()) {
					nxt = xval[*it];
				} else {
					nxt = L;
				}
				it = allx[c].upper_bound(x);
				if (it != allx[c].begin()) {
					prv = posq[*(--it)] + 1;
				}
				//cout << prv << " " << x + 1 << " " << nxt << endl;
				prv = max(prv, tree.get_pos(xval[x]));
				queries.pb({x_ind, {prv, nxt}});
				//tree.change_max(prv, x_ind + 1, nxt);
			}
			sort(queries.rbegin(), queries.rend());
			for (auto t : queries) {
				int x_ind = t.x;
				int prv = t.y.x;
				int nxt = t.y.y;
				tree.change_max(prv, x_ind + 1, nxt);
			}
			pr = y_down + 1;
		}

		for (auto ind : ymp[y_up]) {
			xcur.pb({nx[points[ind].x], color[ind]});
		}
		sort(all(xcur));
		for (int i = 0; i < k; ++i) {
			allx[i].clear();
		}
		for (auto t : xcur) {
			allx[t.y].insert(t.x);
		}
		y_prev = y_up;
	}

	cout << res << "\n";

}