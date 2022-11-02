#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int a = 1234567, b = 123456, c = 1234, n;
	scanf("%d", &n);
	if (n % a == 0 || n % b == 0 || n % c == 0) return puts("YES"), 0;
	int A = 0, B = 0;
	for (int i = 0; ; i++) {
		B = 0;
		for (int j = 0; ; j++) {
			if ((n - A - B) % c == 0) return puts("YES"), 0;
			B += b;
			if (B > n - A) break;
		}
		A += a;
		if (A > n) break;
	}
	return puts("NO"), 0;
}