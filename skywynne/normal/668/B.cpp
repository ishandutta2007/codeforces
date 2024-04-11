#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 2e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, p1, p2, A[N];
int get(int a)
{
    if (a % 2 == 1)
        return (a + 1);
    return (a - 1);
}
int nxt(int a)
{
    a += 2;
    if (a > n)
        a -= n;
    return (a);
}
int main()
{
    scanf("%d%d", &n, &q);
    p1 = 1;
    p2 = 2;
    for (int i = 1; i <= q; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 2)
        {
            p1 = get(p1);
            p2 = get(p2);
            continue;
        }
        scanf("%d", &r);
        p1 = (p1 - 1 + r + n) % n + 1;
        p2 = (p2 - 1 + r + n) % n + 1;
    }
    A[p1] = 1;
    A[p2] = 2;
    for (int i = nxt(p1), w = 3; i != p1; i = nxt(i), w += 2)
        A[i] = w;
    for (int i = nxt(p2), w = 4; i != p2; i = nxt(i), w += 2)
        A[i] = w;
    for (int i = 1; i <= n; i++)
        printf("%d ", A[i]);
    return (0);
}