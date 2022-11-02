#include <bits/stdc++.h>
using namespace std;

long long a, b;

int main() {
	scanf("%I64d %I64d", &b, &a);
	long long rlt;
	rlt = max(0ll, min(a - 1, b * 2 + 1 - a));
	rlt = (rlt + 0) / 2;
	printf("%I64d\n", rlt);

	return 0;
}