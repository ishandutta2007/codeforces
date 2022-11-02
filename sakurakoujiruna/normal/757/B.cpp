#include <bits/stdc++.h>
using namespace std;

const int N = 1e5L + 11;
int cnt[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i ++) {
		int x; cin >> x;
		for(int j = 1; j * j <= x; j ++) if(x % j == 0) {
			cnt[j] ++;
			if(j * j != x)
				cnt[x / j] ++;
		}
	}
	int ans = 1;
	for(int i = 2; i < N; i ++)
		if(cnt[i] > 1)
			ans = max(ans, cnt[i]);
	cout << ans << '\n';
	return 0;
}