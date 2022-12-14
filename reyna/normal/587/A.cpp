//In the name of God
// Break through! I screamed forth from my soul!

#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9;

int cnt[N];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		while (++cnt[x] > 1) {
			cnt[x] = 0;
			x++;	
		}
	}
	int res = 0;
	for (int i = 0; i < N; i++)
		res += cnt[i];
	cout << res << endl;
	return 0;
}