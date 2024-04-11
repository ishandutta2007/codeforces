#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1e3 + 7;
const int INF = 1e9 + 7;

int toH(int a, int b, int c) {
	return a * MAXN * MAXN + b * MAXN + c;
}

void toTrip(int x, int &a, int &b, int &c) {
	c = x % MAXN;
	x /= MAXN;
	b = x % MAXN;
	x /= MAXN;
	a = x;
}

struct Trip {
	int a, b, c, id;
};

bool operator<(Trip a, Trip b) {
	if (a.a != b.a) {
		return a.a < b.a;
	}
	if (a.c != b.c) {
		return a.c > b.c;
	}
	if (a.b != b.b) {
		return a.b;
	}
	return a.id < b.id;
}

bool operator==(Trip a, Trip b) {
	return a.a == b.a && a.b == b.b && a.c == b.c;
}

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <vector <char> > data(n, vector <char> (m));	
	set <Trip> all;
	for (int i = 0; i < n; i++) {
		int a = 0, b = 0, c = 0;
		for (int j = 0; j < m; j++) {
			char t;
			cin >> t;
			data[i][j] = t;
			if (t == '>') {
				a++;
			} else if (t == '<') {
				c++;
			} else {
				b++;
			}
		}
		//cout << a << " " << b << " " << c << "\n";
		all.insert(Trip({a, b, c, i}));
	}
	vector <bool> lt(m, false);
	vector <bool> eq(m, false);
	int a = 0, b = 0, c = m;
	int val = -INF;
	vector <int> resa(n), resb(m);
	for (auto t : all) {
		int i = t.id;
		if (t == Trip({a, b, c, -1})) {
			for (int j = 0; j < m; j++) {
				if (data[i][j] == '=' && !eq[j]) {
					cout << "NO\n";
					return 0;
				}
				if (data[i][j] == '>' && !lt[j]) {
					cout << "NO\n";
					return 0;
				}
			}
			resa[i] = val;
			continue;
		}
		val += MAXN;
		resa[i] = val;
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (eq[j]) {
				lt[j] = true;
			}
		}
		eq.assign(m, false);
		for (int j = 0; j < m; j++) {
			if (data[i][j] == '=') {
				if (lt[j]) {
					cout << "NO\n";
					return 0;
				}
				eq[j] = true;
				resb[j] = val;
			} else if (data[i][j] == '>') {
				if (!lt[j]) {
					lt[j] = true;
					resb[j] = val - 1;
				}
			} else {
				if (lt[j]) {
					cout << "NO\n";
					return 0;
				}
			}
		}
		a = t.a, b = t.b, c = t.c;
	}
	for (int j = 0; j < m; j++) {
		if (eq[j]) {
			resb[j] = val;
		} else if (!lt[j]) {
			resb[j] = val + 1;
		}
	}
	set <int> q;
	for (int x : resa) {
		q.insert(x);
	}
	for (int x : resb) {
		q.insert(x);
	}
	int now = 1;
	map <int, int> valt;
	for (int x : q) {
		valt[x] = now++;
	}
	cout << "YES\n";
	for (int x : resa) {
		cout << valt[x] << " ";
	}
	cout << "\n";
	for (int y : resb) {
		cout << valt[y] << " ";
	}
	cout << "\n";
}