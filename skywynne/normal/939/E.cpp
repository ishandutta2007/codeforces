#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, q, t, p, A[N], P[N];
long double get()
{
    if (n == 1)
        return (0);
    int l = 0, r = n, mid, midd;
    while (r - l > 2)
    {
        mid = (2 * l + r) / 3;
        long double c = P[mid] + A[n - 1]; c /= (mid + 2);
        midd = (2 * r + l) / 3;
        long double cc = P[midd] + A[n - 1]; cc /= (midd + 2);
        if (cc < c)
            l = mid;
        else
            r = midd;
    }
    long double c = P[l] + A[n - 1]; c /= (l + 2);
    long double cc = P[l + 1] + A[n - 1]; cc /= (l + 3);
    long double ccc = P[l + 2] + A[n - 1]; ccc /= (l + 4);
    if (l + 1 >= n)
        cc = A[n - 1];
    if (l + 2 >= n)
        ccc = A[n - 1];
    return (A[n - 1] - min(c, min(cc, ccc)));
}
int main()
{
    scanf("%I64d", &q);
    while (q --)
    {
        scanf("%I64d", &t);
        if (t == 1)
        {
            scanf("%I64d", &A[n]);
            P[n] = A[n];
            if (n > 0)
                P[n] += P[n - 1];
            n ++;
            continue;
        }
        long double res = get();
        cout << fixed << setprecision(12) << res << "\n";
    }
    return (0);
}