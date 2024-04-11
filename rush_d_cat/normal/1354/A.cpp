#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
LL a, b, c, d;
int main() {
	cin >> t;
	while (t --) {
		cin >> a >> b >> c >> d;
		if (a <= b) {
			printf("%lld\n", b); continue;
		} 
		if (c <= d) {
			printf("-1\n"); continue;
		}
		LL res = b;
		LL need = a - b;
		LL val = c - d;
		//printf("ok\n");
		LL cnt = (need + val - 1) / val;
		// printf("cnt = %lld\n", cnt);
		res = res + c * cnt;
		printf("%lld\n", res);
	}
}