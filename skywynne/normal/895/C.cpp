#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 10, NX = 1e9 + 7;
long long n, r, t, c, q, C[10], dp[5000], dp2[5000];
vector < int > P = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}, T = {37, 41, 43, 47, 53, 59, 61, 67};
int main()
{
    dp[0] = 1;
    scanf("%I64d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%I64d", &r);
        q = 0;
        for (int j = 0; j < (int)T.size(); j++)
            if (r == T[j])
                C[j] ++, q = 1;
        if (q == 1)
            continue;
        t = 0;
        for (int j = 0; j < (int)P.size(); j++)
        {
            c = 0;
            while (r % P[j] == 0)
            {
                r /= P[j];
                c ++;
            }
            if (c & 1)
                t += (1 << (j));
        }
        for (int j = 0; j < 4096; j++)
            dp2[j] = (dp[j] + dp[j ^ t]) % NX;
        for (int j = 0; j < 4096; j++)
            dp[j] = dp2[j];
    }
    for (int j = 0; j < 10; j++)
        for (int h = 1; h < C[j]; h++)
            dp[0] = (dp[0] * 2) % NX;
    printf("%I64d", (dp[0] - 1 + NX) % NX);
    return (0);
}