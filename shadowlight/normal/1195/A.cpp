#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	map <int, int> cnt;
	int all = (n + 1) / 2;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
		if (cnt[x] == 2) {
			all--;
			cnt[x] -= 2;
			res += 2;
		}
	}
	res += all;
	cout << res << "\n";
}