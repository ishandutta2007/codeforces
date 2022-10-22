#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1e5 + 7;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int cnt = 0;
	vector <int> ca(MAXN, 0);
	map <int, int> c;
	int mx = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (!ca[x]) {
			cnt++;
		}
		c[ca[x]]--;
		ca[x]++;
		c[ca[x]]++;
		if (c[1] && cnt > 1 && i % (cnt - 1) == 0) {
			int t = i / (cnt - 1);
			c[1]--;
			if (c[t] == cnt - 1) {
				mx = i + 1;
			}
			c[1]++;
		}
		if (i % cnt == 0) {
			int t = i / cnt;
			if (c[t] == cnt - 1 && c[t + 1] == 1) {
				mx = i + 1;
			}
		}
	}
	cout << mx << "\n";
}