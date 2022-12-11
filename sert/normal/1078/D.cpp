#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int M = 19;
const int N = (1 << 19);
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

int my_min(int a, int b) {
	return (a < b ? a : b);
}
int my_max(int a, int b) {
	return (a > b ? a : b);
}
struct ST {
	int ind;
	vector<int> t;
	int (*f) (int, int);

	ST(bool is_mx) {
		if (is_mx) {
			ind = -INF;
			f = my_max;
		} else {
			ind = INF;
			f = my_min;
		}
		t.resize(N * 2);
		for (auto &val : t) val = ind;
	}

	inline int getVal(int pos) {
		return t[pos + N - 1];
	}

	inline void setVal(int pos, int val) {
		int x = pos + N - 1;
		while (true) {
			t[x] = f(t[x], val);
			if (x == 0) break;
			x = (x - 1) / 2;
		}
	}

	inline int getVal(int L, int R) {
		int ans = ind;
		L = L + N - 1;
		R = R + N - 1;
		while (L < R) {
			if (L % 2 == 1) {
				L = (L - 1) / 2;
			} else {
				ans = f(ans, t[L]);
				L = (L - 1) / 2 + 1;
			}

			if (R % 2 == 0) {
				R = (R - 1) / 2;
			} else {
				ans = f(ans, t[R]);
				R = (R - 1) / 2 - 1;
			}
		}
		return (L == R ? f(ans, t[L]) : ans);
	}
};

vector<int> data;

void genTest(int n, int mx) {
	data.resize(n);
	for (int i = 0; i < n; i++) {
		data[i] = rand() % mx + 1;
	}
}

vector<int> stress() {
	int n = data.size();
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int l = 0, r = 0;
		int steps = 0;
		while (l + r + 1 < n) {
			int new_l = 0;
			int new_r = 0;
			for (int j = i - l; j <= i + r; j++) {
				new_l = max(new_l, (i - j) + data[(j + n * 3) % n]);
				new_r = max(new_r, (j - i) + data[(j + n * 3) % n]);
			}
			l = new_l;
			r = new_r;
			steps++;
		}
		ans.push_back(steps);
	}

	return ans;
}

vector<int> solve() {
	int n;
	if (D) n = data.size();
	else cin >> n;
	vector<int> a(n * 3);
	for (int i = 0; i < n; i++) {
		if (D) a[i] = data[i];
		else cin >> a[i];
	}
	for (int i = n; i < n * 3; i++) a[i] = a[i - n];

	vector<ST> l;
	vector<ST> r;
	for (int i = 0; i < M; i++) {
		l.push_back(ST(false));
		r.push_back(ST(true));
	}
	vector<int> ans;

	for (int i = 0; i < n * 3; i++) {
		l[0].setVal(i, max(0, i - a[i]));
		r[0].setVal(i, min(n * 3 - 1, i + a[i]));
	}

	for (int j = 1; j < M; j++) {
		for (int i = 0; i < n * 3; i++) {
			int L = l[j - 1].getVal(i);
			int R = r[j - 1].getVal(i);
			l[j].setVal(i, l[j - 1].getVal(L, R));
			r[j].setVal(i, r[j - 1].getVal(L, R));
		}
	}

	int m = 1;

	for (int i = n; i < n * 2; i++) {		
		m--;
		while (true) {			
			int il = i;
			int ir = i;

			for (int j = M - 1; ir - il + 1 < n && j >= 0; j--) {				
				if ((m & (1 << j)) == 0) continue;
				int new_il = min(il, l[j].getVal(il, ir));
				int new_ir = max(ir, r[j].getVal(il, ir));
				il = new_il;
				ir = new_ir;
			}

			// cout << m << " " << i << " " << il << " " << ir << endl;

			if (ir - il + 1 >= n) {
				ans.push_back(m);
				break;
			} else {
				m++;
			}
		}

		if (!D) cout << ans.back() << " ";
	}
	if (!D) cout << "\n";
	return ans;
}

ostream& operator<<(ostream &fo, vector<int> v) {
	for (int i = 0; i < (int)v.size(); i++) fo << v[i] << " ";
	return fo;
}
void check() {
	int it = 0;
	while (clock() < CLOCKS_PER_SEC * 9.3) {
		it++;
		genTest(12, 5);
		auto st = stress();
		auto sl = solve();

		if (st != sl) {
			cout << "at " << it << "\ndata: ";
			cout << data << "\nstres: ";
			cout << st << "\nsolve: ";
			cout << sl << "\n";
			return;
		}
	}
	cout << it << " is ok!\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	//D = true;	
	//check();
	solve();
	/*tst = 1;
	while (tst--) {
		solve();
	}*/
#else
	solve();
#endif
}