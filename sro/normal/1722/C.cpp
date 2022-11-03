#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

string a[3][1005];

void solve() {
	map<string, int> sc;
	int N; cin >> N;
	for (int i = 0; i < 3; ++i) for (int j = 0; j < N; ++j) {
		cin >> a[i][j];
		++sc[a[i][j]];
	}
	for (int i = 0; i < 3; ++i) {
		int score = 0;
		for (int j = 0; j < N; ++j) {
			int scs = sc[a[i][j]];
			score += (scs == 1 ? 3 : (scs == 2 ? 1 : 0));
		}
		cout << score << (" \n"[i == 2]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}