#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

int n , k , a[10000] , ans;

int main() {
	n = read() , k = read();
	for (int i = 1 ; i <= n ; i ++) a[i] = read();
	for (int i = 2 ; i <= n ; i ++) {
		int now = k - a[i - 1];
		if (now > 0) {
			if (now > a[i]) ans += now - a[i] , a[i] = now;
		}
	}
	printf("%d\n" , ans);
	for (int i = 1 ; i <= n ; i ++) printf("%d " , a[i]);
	return 0;
}