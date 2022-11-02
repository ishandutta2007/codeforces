#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

int prime[40000];

int isprime(long long num)
{
	if(num <= 1)
		return 0;
	long long div;
	for(div=2; div*div<=num; div++)
		if(num%div == 0)
			return 0;
	return 1;
}

int num_prime_div(int n, int k) {
	int div = 2;
	int answer = 0;
	while(div*div <= n) {
		if((div < 40000 && prime[div]) || (div >= 40000 && isprime(div))) {
			while(n%div == 0) {
				n /= div;
				answer++;
				if(answer > k) {
					return answer;
				}
			}
		}
		div++;
	}
	if(n != 1) {
		answer += 1;
	}
	return answer;
}

int main() {
	int h, i, j;
	int t, a, b, k;
	int div;
	for(i=1; i<40000; i++) {
		prime[i] = isprime(i);
	}
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d %d", &a, &b, &k);
		if(k > 64) {
			printf("NO\n");
		} else {
			if(a == b) {
				if(1 != k && k <= num_prime_div(a, k)+num_prime_div(b, k)) {
					printf("YES\n");
				} else {
					printf("NO\n");
				}
			} else if(a%b == 0 || b%a == 0) {
				if(k <= num_prime_div(a, k)+num_prime_div(b, k)) {
					printf("YES\n");
				} else {
					printf("NO\n");
				}
			} else {
				if(1 != k && k <= num_prime_div(a, k)+num_prime_div(b, k)) {
					printf("YES\n");
				} else {
					printf("NO\n");
				}
			}
		}
	}
}