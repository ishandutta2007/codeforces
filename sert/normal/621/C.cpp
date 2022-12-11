#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 3e5 + 34;

int n, pr, r, l, k;
ld p[N], ans;


int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d%d", &n, &pr);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        k = r / pr - (l - 1) / pr;
        p[i] = (k + 0.0) / (r - l + 1.0);
    }

    p[n] = p[0];
    p[n + 1] = p[1];

    for (int i = 1; i <= n; i++) {
        ans += p[i] * 4000;
        ans -= p[i] * p[i - 1] * 2000;
    }

    cout.precision(14);
    cout << fixed << ans;


    return 0;
}