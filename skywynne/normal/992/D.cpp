#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
const long long INF = 2e18 + 10;
int n, r, t, a, b, c, d, k, A[N], nxt[N];
long long p, tot, S[N];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]), S[i] = S[i - 1] + A[i];
    for (int i = 1; i <= n; i++)
    {
        nxt[i] = i - 1;
        if (A[nxt[i]] == 1)
            nxt[i] = nxt[nxt[i]];
    }
    for (int i = 1; i <= n; i++)
    {
        p = A[i];
        long long ksr = k * S[i];
        int len = i - nxt[i] - 1;
        if (A[i] % k == 0 && (A[i] / k) >= A[i] && (A[i] / k) <= A[i] + len)
            tot ++;
        int nw = nxt[i];
        while(nw)
        {
            if (floor(((long double)INF) / p) + 1 <= A[nw])
                break;
            p *= A[nw];
            if (p >= INF)
                break;
            long long tt = ksr - p;
            if (tt < 0)
            {
                nw = nxt[nw];
                continue;
            }
            if (tt % k != 0)
            {
                nw = nxt[nw];
                continue;
            }
            tt /= k;
            len = nw - nxt[nw] - 1;
            if (S[nw - 1] >= tt && S[nxt[nw]] <= tt)
                tot ++;
            nw = nxt[nw];
        }
    }
    printf("%lld", tot);
    return (0);
}