#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 121;

int a[N][5];

int score(int n, int m, int t) {
	if(t == -1) return 0;
	int base = 500;
	if(m * 2 <= n) base = 1000;
	if(m * 4 <= n) base = 1500;
	if(m * 8 <= n) base = 2000;
	if(m * 16 <= n) base = 2500;
	if(m * 32 <= n) base = 3000;
	return base - base / 250 * t;
}

bool check(int n, int m) {
	int ret = 0;
	for(int p = 1; p <= 5; p ++) {
		int s = 0;
		for(int i = 1; i <= n; i ++)
			s += (a[i][p] != -1);
		if(a[1][p] == -1) {
			ret -= score(n + m, s, a[2][p]);
		} else {
			int tmp = -1e9L;
			for(int i = 0; i <= m; i ++)
				tmp = max(tmp, score(n + m, s + i, a[1][p]) - score(n + m, s + i, a[2][p]));
			ret += tmp;
		}
	}
	return ret > 0;
}

int main() {
	ios :: sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= 5; j ++)
			cin >> a[i][j];
	for(int i = 0; i <= n * 40; i ++)
		if(check(n, i)) {
			cout << i << '\n';
			return 0;
		}
	cout << "-1\n";
	return 0;
}