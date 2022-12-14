#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int a[N], n;
long long x;
char c;

int func(long long a) {
    long long u = 1;
    int v = 1, rlt = 0;
    for (;v < N; v <<= 1, u *= 10) {
		rlt += ((a / u) % 2) * v;
    }
    return rlt;
}

int main() {
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i ++) {
        scanf("%c %I64d\n", &c, &x);
        if (c == '+') a[func(x)] ++;
        if (c == '-') a[func(x)] --;
        if (c == '?') printf("%d\n", a[func(x)]);
	}
	return 0;
}