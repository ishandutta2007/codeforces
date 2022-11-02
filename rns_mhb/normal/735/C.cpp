#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define N 1000

ll a[N], n;

int main() {
    scanf("%I64d", &n);
	a[0] = 1;
    a[1] = 2;
	f0(i, 2, N) {
		a[i] = a[i-1] + a[i-2];
        if (a[i] > n) {
			printf("%d\n", i - 1);
			return 0;
        }
	}
	return 0;
}