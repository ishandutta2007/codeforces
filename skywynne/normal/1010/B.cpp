#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, M[N], t;
int main()
{
    scanf("%d%d", &m, &n);
    int l = 1, r = m, mid;
    for (int i = 1; i <= n; i++)
    {
        printf("1\n"); fflush(stdout);
        scanf("%d", &t);
        if (t == 0)
            exit(0);
        if (t == 1)
            M[i] = 1;
    }
    l = 2; r = m + 1;
    int i = 0;
    while (N)
    {
        i ++;
        if (i > n)
            i = 1;
        if (r - l == 1)
        {
            printf("%d\n", l);
            fflush(stdout);
            scanf("%d", &t);
            if (t == 0)
                exit(0);
            assert("What da" == "F***");
        }
        mid = (l + r) >> 1;
        printf("%d\n", mid);
        fflush(stdout);
        scanf("%d", &t);
        if (t == 0)
            exit(0);
        if (!M[i])
            t = -t;
        if (t == -1)
            r = mid;
        if (t == 1)
            l = mid + 1;
    }
    printf("%d\n", l);
    fflush(stdout);
    exit(0);
    return (0);
}