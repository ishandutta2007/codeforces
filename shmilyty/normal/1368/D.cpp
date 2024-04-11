#include <iostream>

using namespace std;

typedef long long ll;

ll cnt[25], n, ans, x;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		for(int j = 0; j < 20; j++) {
			cnt[j] += (x >> j) & 1ll;
		}
	}
	for(int i = 1; i <= n; i++) {
		ll cur = 0;
		for(int j = 0; j < 20; j++) {
			if(cnt[j]) {
				cnt[j]--;
				cur += 1ll << j;
			}
		}
		ans += cur * cur;
	}
	cout << ans << endl;
	return 0;
}