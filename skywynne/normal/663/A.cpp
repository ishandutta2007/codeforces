#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, d, Mn, Mx, A[N], B[N];
char c;
int main()
{
    A[t ++] = 1;
    while((c = getchar()) != -1)
    {
        while (c == ' ' || c == '?')
            c = getchar();
        if (c == '-')
            A[t ++] = -1;
        if (c == '+')
            A[t ++] = 1;
        if (c == '=')
        {
            scanf("%d", &n);
            break;
        }
    }
    Mn += 1;
    Mx += n;
    B[0] = n;
    for (int i = 1; i < t; i++)
    {
        if (A[i] == 1)
        {
            Mn += 1;
            Mx += n;
            B[i] = n;
        }
        if (A[i] == -1)
        {
            Mn -= n;
            Mx -= 1;
            B[i] = -1;
        }
    }
    if (Mx < n || n < Mn)
        return puts("Impossible");
    Mx -= n;
    for (int i = 0; i < t; i++)
    {
        if (Mx == 0)
            continue;
        if (A[i] == 1)
        {
            B[i] -= min(n - 1, Mx);
            Mx -= min(Mx, n - 1);
        }
        if (A[i] == -1)
        {
            B[i] -= min(n - 1, Mx);
            Mx -= min(Mx, n - 1);
        }
    }
    puts("Possible");
    for (int i = 0; i < t; i++)
    {
        if (i != 0)
        {
            if (A[i] == 1)
                printf("+ ");
            if (A[i] == -1)
                printf("- ");
        }
        printf("%d ", abs(B[i]));
    }
    printf("= %d", n);
    return (0);
}