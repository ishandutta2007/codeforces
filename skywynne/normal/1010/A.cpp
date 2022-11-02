#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define ld long double
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, A[N], B[N];
ld dp[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n + n; i += 2)
        scanf("%d", &A[i]);
    for (int i = 0; i <= n + n - 2; i += 2)
        scanf("%d", &A[i]);
    A[n + n] = A[0];
    for (int i = n + n; i; i--)
    {
        if (A[i] == 1)
            return puts("-1");
        dp[i] = (dp[i +1] * A[i] + m) / (A[i] - 1);
    }
    cout << fixed << setprecision(10) << dp[1];
    return (0);
}