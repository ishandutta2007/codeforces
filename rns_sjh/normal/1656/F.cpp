#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 500500;
const int inf = 1e9 + 50;
const int mod = 998244353;

ll A[N], L[N], R[N];

int main() {

    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%lld\n", &A[i]);
        sort(A + 1, A + n + 1);
        L[0] = R[n + 1] = 0;
        for (int i = 1; i <= n; i++) L[i] = A[i] + L[i - 1];
        for (int i = n; i >= 1; i--) R[i] = A[i] + R[i + 1];
        ll ans, tans, pans;
        ll s = A[1] * R[2], t = A[1] * (n - 1) + R[2];
        if (t > 0) {
            printf("INF\n");
            continue;
        }
        ans = s - t * A[1];
        s = A[n] * L[n - 1], t = A[n] * (n - 1) + L[n - 1];
        if (t < 0) {
            printf("INF\n");
            continue;
        }
        ans = min(ans, s - t * A[n]);
        for (int i = 1; i < n; i++) {
            ll s = L[i] * A[n] + A[1] * R[i + 1] - A[1] * A[n];
            ll t = L[i] + R[i + 1] + A[n] * i + A[1] * (n - i) - A[1] - A[n];
            ll tans = 0;
            if (t < 0) tans = s - t * A[i + 1];
            else tans = s - t * A[i];
            ans = max(ans, tans);
        }
        printf("%lld\n", ans);
    }

    return 0;
}