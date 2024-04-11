#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;


int main() {
	scanf("%I64d", &n);
	int ans = 0;
	for (int i = 1; i <= 20; i ++) {
		if (n % 10 == 9) {
			ans += 9;
			n /= 10;
		}
		else {
			ans += n % 10;
			n /= 10;
			if (n > 0) ans += 10;
			n --;
		}
		if (n <= 0) break;
	}
	printf("%d\n", ans);
	return 0;
}