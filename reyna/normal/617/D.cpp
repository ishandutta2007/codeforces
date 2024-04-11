//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 0;

int read() { int x; cin >> x; return x; }

int x[3], y[3];

void ex(int a) {
	cout << a;
	exit(0);
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 3; ++i)
		cin >> x[i] >> y[i];
	int fl = 1;
	for (int i = 1; i < 3; ++i)
		if (x[i] != x[i - 1])
			fl = 0;
	if (fl)
		ex(1);
	fl = 1;
	for (int i = 1; i < 3; ++i)
		if (y[i] != y[i - 1])
			fl = 0;
	if (fl)
		ex(1);
	for (int i = 0; i < 3; ++i)
		for (int l = 0; l < 3; ++l) if (i != l) {
			int r = 3 - i - l;
			if (x[i] == x[l] && y[i] == y[r])
				ex(2);
		}
	for (int i = 0; i < 3; ++i)
		for (int l = 0; l < 3; ++l) if (i != l) {
			int r = 3 - i - l;
			if (x[i] == x[l]) {
				if (y[r] < min(y[i], y[l]) || y[r] > max(y[i], y[l]))
					ex(2);
			}
			if (y[i] == y[l]) {
				if (x[r] < min(x[i], x[l]) || x[r] > max(x[i], x[l]))
					ex(2);
			}
		}
	ex(3);
}