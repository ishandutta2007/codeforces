#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2e5 + 7;
const ll INF = (ll) 1e18 + 7;

ll mink[4 * N], val[4 * N];

void add_val(int v, ll valt) {
	mink[v] += valt;
	val[v] += valt;
}

void push(int v) {
	add_val(2 * v, val[v]);
	add_val(2 * v + 1, val[v]);
	val[v] = 0;
} 

void relax(int v) {
	mink[v] = min(mink[2 * v], mink[2 * v + 1]);
}

void add(int l, int r, int valt, int vt = 1, int lt = 0, int rt = N) {
	if (l >= rt || lt >= r) {
		return;
	}
	if (l <= lt && rt <= r) {
		add_val(vt, valt);
		return;
	}
	push(vt);
	int mt = (lt + rt) / 2;
	add(l, r, valt, 2 * vt, lt, mt);
	add(l, r, valt, 2 * vt + 1, mt, rt);
	relax(vt);
}

ll get(int l, int r, int vt = 1, int lt = 0, int rt = N) {
	if (l >= rt || lt >= r) {
		return INF;
	}
	if (l <= lt && rt <= r) {
		return mink[vt];
	}
	push(vt);
	int mt = (lt + rt) / 2;
	ll res = get(l, r, 2 * vt, lt, mt);
	res = min(res, get(l, r, 2 * vt + 1, mt, rt));
	relax(vt);
	return res;
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> p(n), a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		add(p[i], n + 1, a[i]);
	}

	ll res = INF;

	for (int i = 0; i < n - 1; i++) {
		add(p[i], n + 1, -a[i]);
		add(0, p[i], a[i]);
		res = min(res, get(0, n + 1));
		//cout << get(3, 4) << "\n";
	}
	cout << res << "\n";

}