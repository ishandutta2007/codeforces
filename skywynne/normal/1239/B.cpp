// In The Name Of The Queen
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define lc (id << 1)
#define rc (lc ^ 1)
#define md ((l + r) >> 1)
using namespace std;
const int N = 3e5 + 100;
int n, m, q, P[N], F[N], pre[N], suf[N];
char A[N * 2], B[N];
int mxans = 0, lans = 1, rans = 1;
inline void Check(int l, int r, int st)
{
    swap(B[l], B[r]);
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
    {
        P[i] = P[i - 1] + B[i];
        if (P[i] < 0) return ;
        cnt += P[i] == 0;
    }
    if (cnt > mxans)
    {
        l = (l + st - 1);
        r = (r + st - 1);
        if (l > n) l -= n;
        if (r > n) r -= n;
        mxans = cnt;
        lans = l;
        rans = r;
    }
}
inline void Solve(int st)
{
    for (int i = 1; i <= n; i ++)
        B[i] = A[st + i - 1];
    int fir = 0, sec = 0;
    for (int i = 1; i <= n; i ++)
    {
        P[i] = P[i - 1] + B[i];
        if (P[i] < -2) return ;
        if (P[i] < 0 && !fir)
            fir = i;
        if (P[i] < 0)
            sec = i;
    }
    if (fir)
    {
        Check(fir, sec + 1, st);
        return ;
    }
    int Mx = 0;
    int le = 1, ri = 1;
    for (int l = 1; l <= n; l ++)
    {
        int r = l, cnt = 0;
        while (r <= n && P[r] >= 2)
            cnt += (P[r] == 2), r ++;
        if (cnt > Mx)
        {
            Mx = cnt;
            le = l;
            ri = r;
        }
        l = r;
    }
    Check(le, ri, st);
}
int main()
{
    scanf("%d%s", &n, &A[1]);
    for (int i = 1; i <= n; i ++)
    {
        if (A[i] == '(') A[i] = 1;
        else A[i] = -1;
    }
    for (int i = 1; i <= n; i ++)
        F[i] = F[i - 1] + A[i];
    if (F[n] != 0)
        return !printf("0\n1 1\n");
    pre[1] = F[1];
    suf[n] = F[n];
    for (int i = 2; i <= n; i ++)
        pre[i] = min(pre[i - 1], F[i]);
    for (int i = n - 1; i >= 1; i --)
        suf[i] = min(suf[i + 1], F[i]);
    for (int i = 1; i <= n; i ++)
        A[i + n] = A[i];
    Solve(1);
    int tof = 285;
    for (int i = 1; i <= n - 1 && tof > 0; i ++)
        if (pre[i] - F[i] >= -2 && suf[i + 1] - F[i] >= -2)
            Solve(i + 1), tof --;
    printf("%d\n%d %d\n", mxans, lans, rans);
    return 0;
}