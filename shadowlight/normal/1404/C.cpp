#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 3e5 + 7;
const int SQ = sqrt(N);
//const int SQ = 10;
const int INF = 1e9 + 7;

vector <pair <int, int> > queries;
vector <int> deleted;

pair <int, int> t[4 * SQ];
int val[4 * SQ];

void relax(int v) {
	t[v] = min(t[2 * v + 1], t[2 * v]);
}

void build(int v, int l, int r, vector<pair<int, int> >& a) {
	val[v] = 0;
	if (r - l == 1) {
		t[v] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(2 * v, l, m, a);
	build(2 * v + 1, m, r, a);
	relax(v);
}

void add_val(int v, int x) {
	t[v].x += x;
	val[v] += x;
}

void push(int v) {
	add_val(2 * v, val[v]);
	add_val(2 * v + 1, val[v]);
	val[v] = 0;
}

void add_seg(int l, int r, int valt, int vt = 1, int lt = 0, int rt = SQ) {
	if (lt >= r || l >= rt) {
		return;
	}
	if (l <= lt && rt <= r) {
		add_val(vt, valt);
		return;
	}
	int mt = (lt + rt) / 2;
	push(vt);
	add_seg(l, r, valt, 2 * vt, lt, mt);
	add_seg(l, r, valt, 2 * vt + 1, mt, rt);
	relax(vt);
}

pair <int, int> get_min(int l, int r, int vt = 1, int lt = 0, int rt = SQ) {
	if (l >= rt || lt >= r) {
		return {INF, -1};
	}
	if (l <= lt && rt <= r) {
		//cout << lt << " " << rt << " " << t[vt].x << " " << t[vt].y << "\n";
		return t[vt];
	}
	push(vt);
	int mt = (lt + rt) / 2;
	auto x = get_min(l, r, 2 * vt, lt, mt);
	auto y = get_min(l, r, 2 * vt + 1, mt, rt);
	relax(vt);
	return min(x, y);
}

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
	vector<int> need(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		need[i] = i - a[i];
		if (need[i] < 0) {
			need[i] = INF;
		}
	}
	/*for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		int l = x, r = n - y - 1;
		int cur = 0;
		int deleted = 0;
		for (int t = l; t <= r; ++t) {
			if (a[t] >= t - deleted && a[t] <= t + deleted) {
				++deleted;
			} 
			//cout << a[t] << " " << t << " " << deleted << "\n";
		}
		cout << deleted << "\n";
	}*/
	deleted.resize(q, 0);
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		queries.pb({x, n - 1 - y});
	}
	for (int l = 0; l < n; l += SQ) {
		vector<int> next_delete(n + 1, 0);
		vector <pair <int, int> > values;
		for (int a = l; a < min(n, l + SQ); ++a) {
			values.pb({need[a], a});
			//cout << need[a] << " ";
		}
		if (values.size() < SQ) break;

		build(1, 0, SQ, values);
		auto [val, pos] = get_min(0, values.size());
		
		int current = 0;
		for (int prev_delete = 0; prev_delete <= n; ++prev_delete) {
			while (true) {
				auto [val, pos] = get_min(0, values.size());
				pos -= l;
				if (val > 0) break;
				//cout << "SEG: " << l << " " << prev_delete << " " << val << " " << pos << endl;
				add_seg(pos, SQ, -1);
				add_seg(pos, pos + 1, INF);
				++current;
			}
			add_seg(0, values.size(), -1);
			next_delete[prev_delete] = current;
			++current;
		}

		for (int i = 0; i < q; ++i) {
			while (queries[i].x < l && queries[i].x <= queries[i].y) {
				deleted[i] += (deleted[i] >= need[queries[i].x]);
				++queries[i].x;
			}
			if (queries[i].x > l) continue;
			if (queries[i].y >= l + SQ) {
				deleted[i] = next_delete[deleted[i]];
				queries[i].x += SQ;
			}
		}
	}
	for (int i = 0; i < q; ++i) {
			while (queries[i].x <= queries[i].y) {
				deleted[i] += (deleted[i] >= need[queries[i].x]);
				++queries[i].x;
			}
	
	}
	for (int i = 0; i < q; ++i) {
		cout << deleted[i] << "\n";
	}
}