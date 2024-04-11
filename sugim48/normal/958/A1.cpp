#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)

vector<string> flip(vector<string> a) {
	int N = a.size();
	vector<string> b(N, string(N, ' '));
	rep(y, N) rep(x, N) b[y][N - 1 - x] = a[y][x];
	return b;
}

vector<string> rotate(vector<string> a) {
	int N = a.size();
	vector<string> b(N, string(N, ' '));
	rep(y, N) rep(x, N) b[x][N - 1 - y] = a[y][x];
	return b;
}

int main() {
	int N; cin >> N;
	vector<string> a(N), b(N);
	rep(y, N) cin >> a[y];
	rep(y, N) cin >> b[y];
	rep(t, 2) {
		rep(k, 4) {
			if (a == b) {
				cout << "Yes" << endl;
				return 0;
			}
			a = rotate(a);
		}
		a = flip(a);
	}
	cout << "No" << endl;
}