#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b;

ll func(ll a, ll b) {
	if (a == b) return 1;
	if (a < b) swap(a, b);
	if (!b) return 0;
	ll c = a / b;
    return c + func(a - b * c, b);
}

int main() {
	scanf("%I64d %I64d", &a, &b);
	printf("%I64d\n", func(a, b));
	return 0;
}