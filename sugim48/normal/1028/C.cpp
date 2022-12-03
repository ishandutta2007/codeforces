#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)

bool f(int x, int y, int N, vector<int> xl, vector<int> yl, vector<int> xr, vector<int> yr) {
	int cnt = 0;
	rep(i, N) {
		if (xl[i] <= x && x <= xr[i] && yl[i] <= y && y <= yr[i]) {
			cnt++;
		}
	}
	return cnt >= N - 1;
}

int main() {
	int N; cin >> N;
	vector<int> x1(N), y1(N), x2(N), y2(N);
	rep(i, N) {
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
	}
	int xl = INT_MIN, yl = INT_MIN, xr = INT_MAX, yr = INT_MAX;
	rep(i, N) {
		xl = max(xl, x1[i]);
		yl = max(yl, y1[i]);
		xr = min(xr, x2[i]);
		yr = min(yr, y2[i]);
	}
	if (f(xl, yl, N, x1, y1, x2, y2)) {
		cout << xl << ' ' << yl << endl;
		return 0;
	}
	if (f(xl, yr, N, x1, y1, x2, y2)) {
		cout << xl << ' ' << yr << endl;
		return 0;
	}
	if (f(xr, yl, N, x1, y1, x2, y2)) {
		cout << xr << ' ' << yl << endl;
		return 0;
	}
	if (f(xr, yr, N, x1, y1, x2, y2)) {
		cout << xr << ' ' << yr << endl;
		return 0;
	}
}