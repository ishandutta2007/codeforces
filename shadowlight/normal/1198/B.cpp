#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> a, t, val;
int n;

void add_val(int v, int x) {
	t[v] = max(t[v], x);
	val[v] = max(val[v], x);
}

void push(int v) {
	add_val(2 * v, val[v]);
	add_val(2 * v + 1, val[v]);
	val[v] = 0;
}

void change(int p, int x, int v = 1, int l = 0, int r = n) {
	if (p < l || p >= r) {
		return;
	}
	if (r - l == 1) {
		t[v] = x;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	change(p, x, 2 * v, l, m);
	change(p, x, 2 * v + 1, m, r);
}

void print(int v = 1, int l = 0, int r = n) {
	if (r - l == 1) {
		cout << t[v] << " ";
		return;
	}
	push(v);
	int m = (l + r) / 2;
	print(2 * v, l, m);
	print(2 * v + 1, m, r);
}

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	t.resize(4 * n);
	val.resize(4 * n, 0);
	for (int i = 0; i < n; i++) {
		change(i, a[i]);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int p, x;
			cin >> p >> x;
			p--;
			change(p, x);
		} else {
			int x;
			cin >> x;
			add_val(1, x);
		}
	}
	print();
}