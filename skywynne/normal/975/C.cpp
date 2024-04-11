#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, k, d, A[N], P[N];
string s;
int32_t main()
{
    scanf("%lld%lld", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &A[i]), P[i] = P[i - 1] + A[i];
    r = 1; t = A[1];
    P[n + 1] = 1e17;
    while (q --)
    {
        scanf("%lld", &k);
        if (t - k > 0)
        {
            t -= k;
            printf("%lld\n", n - r + 1);
            continue;
        }
        if (t == k)
        {
            if (r == n)
                printf("%lld\n", n);
            else
                printf("%lld\n", n - r);
            r = r % n + 1;
            t = A[r];
            continue;
        }
        k -= t;
        if (r == n)
        {
            printf("%lld\n", n);
            r = 1; t = A[1];
            continue;
        }
        int lb = upper_bound(P + r + 1, P + n + 2, k + P[r]) - P;
        if (lb == n + 1)
        {
            printf("%lld\n", n);
            r = 1; t = A[1];
            continue;
        }
        t = A[lb] - (k - (P[lb - 1] - P[r]));
        r = lb;
        printf("%lld\n", n - r + 1);
    }
    return (0);
}