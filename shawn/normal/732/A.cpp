#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

int n , k , ans;

int main() {
	n = read() , k = read();
	for (ans = 1 ; ; ans ++) {
		int sum = ans * n;
		if (sum % 10 == k || sum % 10 == 0) break;
	}	
	printf("%d\n" , ans);
	return 0;
}