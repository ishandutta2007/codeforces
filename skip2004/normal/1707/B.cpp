#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 500005;
int a[N], b[N];
int n;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	for(int i = 0;i < t;++i) {
		cin >> n;
		for(int i = 1;i <= n;++i) {
			cin >> a[i];
		}
		int zc = 0;
		for(;n > 1;) {
			int m = 0, sub = !!zc;
			for(int j = 2-sub;j <= n;++j) {
				int d = a[j] - a[j - 1];
				if(d != 0) b[++m] = d;
				else zc += 1;
			}
			zc -= sub;
			std::sort(b + 1, b + m + 1);
			memcpy(a + 1, b + 1, m << 2);
			n = m;
		}
		cout << (n ? a[1] : 0) << '\n';

	}
}