#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int MXN = 2010;
long long n, m, p, l, r, mid;
long long s, t, c, Mns = 1e18, Mnp = 1e18;
pair < long long , long long > A[MXN], B[MXN], Pr, Tr[2];
pair < long long , pair < long long , long long > > P[MXN * MXN / 2];
int main()
{
    scanf("%I64d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%I64d", &A[i].x);
        A[i].y = i + 1;
        s += A[i].x;
    }
    scanf("%I64d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%I64d", &B[i].x);
        B[i].y = i + 1;
        t += B[i].x;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            P[p].x = B[i].x + B[j].x;
            P[p].y.x = B[i].y;
            P[p ++].y.y = B[j].y;
        }
    }
    sort(P, P + p);
    sort(B, B + m);
    for (int i = 0; i < n; i++)
    {
        c = (t - s + 2 * A[i].x + 1) / 2;
        if (s > t)
        {
            c = -(s - t - 2 * A[i].x + 1) / 2;
        }
        r = m;
        l = -1;
        while (r - l > 1)
        {
            mid = (l + r) / 2;
            if (B[mid].x < c)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        if (Mns > abs(s - t - 2 * A[i].x + 2 * B[r].x) && r < m)
        {
            Mns = abs(s - t - 2 * A[i].x + 2 * B[r].x);
            Pr.x = A[i].y;
            Pr.y = B[r].y;
        }
        if (r == 0)
        {
            continue;
        }
        if (Mns > abs(s - t - 2 * A[i].x + 2 * B[r - 1].x))
        {
            Mns = abs(s - t - 2 * A[i].x + 2 * B[r - 1].x);
            Pr.x = A[i].y;
            Pr.y = B[r - 1].y;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            c = (t - s + 2 * A[i].x + 2 * A[j].x + 1) / 2;
            if (s > t)
            {
                c = -(s - t - 2 * A[i].x - 2 * A[j].x + 1) / 2;
            }
            l = -1;
            r = p;
            while (r - l > 1)
            {
                mid = (l + r) / 2;
                if (P[mid].x < c)
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
            if (Mnp > abs(s - t - 2 * A[i].x - 2 * A[j].x + 2 * P[r].x) && r < p)
            {
                Mnp = abs(s - t - 2 * A[i].x - 2 * A[j].x + 2 * P[r].x);
                Tr[0].x = A[i].y; Tr[0].y = A[j].y;
                Tr[1].x = P[r].y.x; Tr[1].y = P[r].y.y;
            }
            if (r == 0)
            {
                continue;
            }
            if (Mnp > abs(s - t - 2 * A[i].x - 2 * A[j].x + 2 * P[r - 1].x))
            {
                Mnp = abs(s - t - 2 * A[i].x - 2 * A[j].x + 2 * P[r - 1].x);
                Tr[0].x = A[i].y; Tr[0].y = A[j].y;
                Tr[1].x = P[r - 1].y.x; Tr[1].y = P[r - 1].y.y;
            }
        }
    }
    if (abs(t - s) <= Mns && abs(t - s) <= Mnp)
    {
        printf("%I64d\n0", abs(s - t));
        return(0);
    }
    if (Mns <= Mnp)
    {
        printf("%I64d\n1\n%I64d %I64d", Mns, Pr.x, Pr.y);
        return(0);
    }
    printf("%I64d\n2\n%I64d %I64d\n%I64d %I64d", Mnp, Tr[0].x, Tr[1].x, Tr[0].y, Tr[1].y);
    return(0);
}