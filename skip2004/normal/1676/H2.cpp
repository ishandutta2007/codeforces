#include<iostream>
#include<cstring>
#include<algorithm>
using std::cin;
using std::cout;

const int N = 200005;
int t, n;
int a[N];
int bit[N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;++i) {
		cin >> n;
		for(int i = 0;i < n;++i) {
			cin >> a[i];
		}
		memset(bit, 0, (n + 1) << 2);
		long long ans = 0;
		for(int i = 0;i < n;++i) {
			for(int j = a[i];j <= n;j += j & -j) {
				ans += bit[j];
			}
			for(int j = a[i];j;j &= j - 1) {
				bit[j] += 1;
			}
		}
		cout << ans << '\n';
	}
}