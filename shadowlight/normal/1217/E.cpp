#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MAXN = 8e5;
const int INF = 2e9 + 7;

vector <int> t[MAXN];
int rest[MAXN];

pair <vector <int>, int> update(vector <int> &a, vector <int> &b, int resa, int resb) {
	vector <int> c(10);
	int res = min(resa, resb);
	for (int i = 0; i < 10; i++) {
		//cout << a[i] << " " << b[i] << "\n";
		c[i] = min(a[i], b[i]);
		if (a[i] < INF && b[i] < INF && res > a[i] + b[i]) {
			res = a[i] + b[i];
		}
	}
	//cout << "RES: " << res << " " << resa << " " << resb << "\n";
	return {c, res};
}

void relax(int v) {
	auto tt = update(t[2 * v], t[2 * v + 1], rest[2 * v], rest[2 * v + 1]);
	t[v] = tt.first;
	rest[v] = tt.second;
}

int n, m;
vector <int> a;

void build(int lt = 0, int rt = n, int vt = 1) {
	if (rt - lt == 1) {
		rest[vt] = INF;
		int x = a[lt];
		t[vt].resize(10);
		for (int i = 0; i < 10; i++) {
			if (x % 10 != 0) {
				t[vt][i] = a[lt];
			} else {
				t[vt][i] = INF;
			}
			x /= 10;
		}
		return;
	}
	int mt = (lt + rt) / 2;
	build(lt, mt, 2 * vt);
	build(mt, rt, 2 * vt + 1);
	relax(vt);
	//cout << vt << " " << rest[vt] << "\n";
}

void change(int pos, int x, int lt = 0, int rt = n, int vt = 1) {
	if (rt <= pos || lt > pos) {
		return;
	}
	if (rt - lt == 1) {
		rest[vt] = INF;
		int sx = x;
		for (int i = 0; i < 10; i++) {
			if (x % 10 != 0) {
				t[vt][i] = sx;
			} else {
				t[vt][i] = INF;
			}
			x /= 10;
		}
		return;
	}
	int mt = (lt + rt) / 2;
	change(pos, x, lt, mt, 2 * vt);
	change(pos, x, mt, rt, 2 * vt + 1);
	relax(vt);
}

vector <int> infs(10, INF);

pair <vector <int>, int> get_res(int l, int r, int lt = 0, int rt = n, int vt = 1) {
	if (l >= rt || lt >= r) {
		return {infs, INF}; 
	}
	if (l <= lt && rt <= r) {
		//cout << lt << " " << rt << "\n";
		return {t[vt], rest[vt]};
	}
	int mt = (lt + rt) / 2;
	auto a = get_res(l, r, lt, mt, 2 * vt), b = get_res(l, r, mt, rt, 2 * vt + 1);
	return update(a.first, b.first, a.second, b.second);
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];	
	}
	build();
	for (int i = 0; i < m; i++) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int v, x;
			cin >> v >> x;
			v--;
			change(v, x);
		} else {
			int l, r;
			cin >> l >> r;
			l--;
			auto tt = get_res(l, r);
			cout << (tt.second == INF ? -1 : tt.second) << "\n";
		}
	}
}