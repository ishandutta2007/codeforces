#include <bits/stdc++.h>
using namespace std;

int t;
long long a, b;

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%lld %lld", &a, &b);
        if (a > b + 1) puts("NO");
        else {
            a += b;
            int p;
            for (p = 2; 1ll * p * p <= a; p ++)
                if (a % p == 0) break;
            if (1ll * p * p <= a) puts("NO");
            else puts("YES");
        }
    }
}