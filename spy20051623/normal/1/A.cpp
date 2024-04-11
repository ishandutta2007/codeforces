#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	long long n, m, k, s;
	scanf("%lld%lld%lld", &n, &m, &k);
	s = ((n - 1) / k + 1) * ((m - 1) / k + 1);
	printf("%lld\n", s);
	return 0;
}