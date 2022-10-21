#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 200500;
const int inf = 1e9 + 50;
const int mod = 998244353;

int main() {

    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        ll n;
        scanf("%lld", &n);
        if (n % 2 == 1) {
            printf("2\n");
            continue;
        }
        ll t = n, tt = 2;
        while (t % 2 == 0) tt *= 2, t /= 2;
        if (t != 1 && t / 2 <= sqrt(1.0 * n) && t * (t + 1) / 2 <= n) {
            printf("%lld\n", t);
        }
        else if (tt / 2 <= sqrt(1.0 * n) && tt * (tt + 1) / 2 <= n) {
            printf("%lld\n", tt);
        }
        else printf("-1\n");
    }

    return 0;
}