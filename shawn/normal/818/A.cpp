#include <bits/stdc++.h>

using namespace std;

long long n, k, A, B;
int main() {
	scanf("%lld%lld", &n, &k);
	B = n / 2 / (k + 1);
	A = B * k;
	printf("%lld %lld %lld\n", B, A, n - A - B);
}