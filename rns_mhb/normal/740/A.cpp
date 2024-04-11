#include <bits/stdc++.h>
using namespace std;

int n;
long long a, b, c, d[5];

int main(){
	scanf("%d %I64d %I64d %I64d", &n, &a, &b, &c);
	d[1] = min(min(a, b + c), c * 3);
	d[2] = min(min(b, a * 2), c * 2);
	d[3] = min(min(c, a + b), 3 * a);
	d[4] = 0;
	printf("%I64d", d[4 - n % 4]);
}