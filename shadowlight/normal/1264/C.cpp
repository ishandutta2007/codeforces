#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 998244353;
const int N = 2e5 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
	if (x < 0) {
		x += MOD;
	}
}

void mul(int &x, int y) {
	x = x * (ll) y % MOD;
}

int power(int a, int k) {
	if (!k) {
		return 1;
	}
	int b = power(a, k / 2);
	b = b * (ll) b % MOD;
	if (k % 2) {
		return a * (ll) b % MOD; 
	} else {
		return b;
	}
}


int rev(int a) {
	return power(a, MOD - 2);
}

int sum[4 * N], mt[4 * N];
int p[N];

int get_res(int suma, int sumb, int mb) {
	mul(suma, mb);
	add(suma, sumb);
	return suma;
}

void relax(int v) {
	sum[v] = get_res(sum[2 * v], sum[2 * v + 1], mt[2 * v + 1]);  
	mt[v] = mt[2 * v + 1] * (ll) mt[2 * v] % MOD;
}

pair <int, int> get(int l, int r, int vt = 1, int lt = 0, int rt = N) {
	if (l >= rt || lt >= r) {
		return {0, 1};
	}
	if (l <= lt && rt <= r) {
		return {sum[vt], mt[vt]};
	}
	int mt = (lt + rt) / 2;
	auto ta = get(l, r, 2 * vt, lt, mt);
	auto tb = get(l, r, 2 * vt + 1, mt, rt);
	pair <int, int> tt = {get_res(ta.first, tb.first, tb.second), ta.second * (ll) tb.second % MOD};
	return tt;
}

void build(int vt = 1, int lt = 0, int rt = N) {
	if (rt - lt == 1) {
		sum[vt] = p[lt];
		mt[vt] = p[lt];
		return;
	}
	int mt = (lt + rt) / 2;
	build(2 * vt, lt, mt);
	build(2 * vt + 1, mt, rt);
	relax(vt);
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, qq;
	cin >> n >> qq;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		mul(p[i], rev(100));
		p[i] = rev(p[i]);
	}
	vector <int> e(n + 1, -1);
	e[n] = 0;
	set <int> q;
	build();
	q.insert(0);
	q.insert(n);
	int res = get(0, n).first; 
	for (int i = 0; i < qq; i++) {
		int pos;
		cin >> pos;
		pos--;
		if (q.find(pos) != q.end()) {
			q.erase(pos);
			auto it = q.lower_bound(pos);
			int r = *it;
			it--;
			int l = *it;
			add(res, -get(l, pos).first);
			add(res, -get(pos, r).first);
			add(res, get(l, r).first);
		} else {
			auto it = q.lower_bound(pos);
			int r = *it;
			it--;
			int l = *it;
			q.insert(pos);
			add(res, get(l, pos).first);
			add(res, get(pos, r).first);
			add(res, -get(l, r).first);
		}
		cout << res << "\n";
	}
}