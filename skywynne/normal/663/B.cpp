#include<bits/stdc++.h>
#define pb push_back
#define x first
#define int long long
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, A[N], P[18];
char S[N];
int gett()
{
    int a = strlen(S), b= 1, ret = 0;
    for (int i = a - 1; ~i; i--, b *= 10)
    {
        ret += (S[i] - '0') * b;
    }
    return (ret);
}
int get()
{
    int a = gett();
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 90; j += 10)
            for (int h = 0; h <= 900; h+= 100)
                if (A[n] <= (i + j + h) * P[n] + a && (i + j + h) * P[n] + a < A[n + 1])
                    return ((i + j + h) * P[n] + a);
}
int32_t main()
{
    scanf("%lld", &q);
    t ++;
    A[t ++] = 1989;
    P[0] = 1;
    for (int i = 1; i < 20; i++)
        P[i] = P[i - 1] * 10;
    for (int a = 10; A[t - 1] <= 1e9; a *= 10)
        A[t] = A[t - 1] + a, t ++;
    for (int i = 0; i < q; i++)
    {
        char ch;
        for (int j = 0; j < 5; j++)
            ch = getchar();
        scanf("%s", &S);
        n = strlen(S);
        printf("%lld\n", get());
    }
    return (0);
}