#include <bits/stdc++.h>
using namespace std;
int t, n;
bool isp(int x) {
	if (x == 2) return 1;
	//printf("x = %d\n", x);
	for (int i = 2; i * i <= x; i ++) {
		//printf("%d %d\n", x, i);
		if (x % i == 0) return 0;
	}
	//printf("win\n");
	return 1;
}
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);

		if (n==1) {
			printf("FastestFinger\n"); continue;
		} else if (n == 2) {
			printf("Ashishgup\n"); continue;
		}

		if (n % 2 == 1) {
			printf("Ashishgup\n");
		} else {
			int x = n, y = 1;
			while (x % 2 == 0) x /= 2, y *= 2;
			
			if (x == 1) {
				// 2 ^ k (k >= 2): N
				printf("FastestFinger\n");
			} else if (y >= 4)  {
				// k >= 2    2 ^ k * odd : P
				printf("Ashishgup\n");
			} else {
				// 2 * odd
				//printf("check %d\n", x);
				if (isp(x)) {
					//printf("!\n");
					printf("FastestFinger\n");
				} else {
					//printf("@\n");
					printf("Ashishgup\n");
				}
				//printf("end\n");
			}
		}
	}
}
/*
2^k
2 P
N


odd: P


2 * prime: N
2 * primes: P
2 ^ k * prime (k >= 2)
*/