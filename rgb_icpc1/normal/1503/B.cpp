#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;
const int MN = 1000005;
const int M = 998244353;
vector<pii> V[3];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) V[((i + j) & 1) + 1].push_back(pii(i, j));
	for (int i = 1; i <= n * n; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			if (V[2].empty()) {
				pii p = V[1].back(); V[1].pop_back();
				cout << 3 << ' ' << p.first << ' ' << p.second << endl;
			}
			else {
				pii p = V[2].back(); V[2].pop_back();
				cout << 2 << ' ' << p.first << ' ' << p.second << endl;
			}
		}
		if (a == 2) {
			if (V[1].empty()) {
				pii p = V[2].back(); V[2].pop_back();
				cout << 3 << ' ' << p.first << ' ' << p.second << endl;
			}
			else {
				pii p = V[1].back(); V[1].pop_back();
				cout << 1 << ' ' << p.first << ' ' << p.second << endl;
			}
		}
		if (a == 3) {
			if (V[2].empty()) {
				pii p = V[1].back(); V[1].pop_back();
				cout << 1 << ' ' << p.first << ' ' << p.second << endl;
			}
			else {
				pii p = V[2].back(); V[2].pop_back();
				cout << 2 << ' ' << p.first << ' ' << p.second << endl;
			}
		}
		cout.flush();
	}

	return 0;
}