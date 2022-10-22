#include<bits/stdc++.h>
const int maxn = 100100;
typedef double db;
using std::cin;
int n;
db a[maxn];
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) {
		char x; cin >> x;
		a[i] = x & 15;
	}
	for(int i = 1;i < n;++i) if(n % i == 0) {
		for(int j = 1;j <= i;++j) {
			db sum = 0;
			for(int k = j;k <= n;k += i) sum += a[k];
			sum /= n / i;
			for(int k = j;k <= n;k += i) a[k] -= sum;
		}
	}
	for(int i = 1;i <= n;++i) if(std::fabs(a[i]) > 1e-9) {
		puts("NO");
		return 0;
	}
	puts("YES");
}