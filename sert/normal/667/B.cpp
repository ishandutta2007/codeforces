#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 34;
typedef long double ld;
typedef long long ll;
const ld pi = atan2l(0, -1);
const ld eps = 1e-9;

ll n, x, mx = -1, sum;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%I64d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += x;
        mx = max(mx, x);
    }
    printf("%I64d", mx * 2 - sum + 1);



    return 0;
}