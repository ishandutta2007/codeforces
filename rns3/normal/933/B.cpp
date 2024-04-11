#include <bits/stdc++.h>
using namespace std;

long long p;
int k;

int a[1000000];

int main() {
	//freopen("r.in", "r", stdin);
    scanf("%I64d %d", &p, &k);
    int d = 1, as = 0, x;
    while (p) {
		x = (p % k + k) % k;
        a[as ++] = x;
        p = (p - x) / k;
        p = -p;
    }
    printf("%d\n", as);
    for (int i = 0; i < as; i ++) printf("%d ", a[i]);

    return 0;
}