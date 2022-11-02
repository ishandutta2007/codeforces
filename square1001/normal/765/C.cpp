#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
	cin >> n >> a >> b;
	int p = a / n, q = b / n;
	if(a - p * n > q * (n - 1) || b - q * n > p * (n - 1)) puts("-1");
	else printf("%d\n", p + q);
	return 0;
}