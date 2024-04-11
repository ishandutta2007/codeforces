#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;

int f(string s, int T) {
	int N = s.length();
	if (N == 1) return 1;
	vector<int> a(256);
	for (char c: s) a[c]++;
	int ma = 0;
	for (int x: a) ma = max(ma, x);
	if (T == 1) return ma == N ? N - 1 : ma + 1;
	else return min(N, ma + T);
}

int main() {
	int T; cin >> T;
	vector<string> a(3);
	cin >> a[0] >> a[1] >> a[2];
	vector<int> b(3);
	rep(i, 3) b[i] = f(a[i], T);
	if (b[0] > b[1] && b[0] > b[2]) {
		cout << "Kuro" << endl;
		return 0;
	}
	if (b[1] > b[2] && b[1] > b[0]) {
		cout << "Shiro" << endl;
		return 0;
	}
	if (b[2] > b[0] && b[2] > b[1]) {
		cout << "Katie" << endl;
		return 0;
	}
	cout << "Draw" << endl;
}