// I'm back b*tches
#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 3e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, d, A[N], C[2][N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a), A[i] = A[i - 1] ^ a;
    C[0][A[0]] ++;
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        tot += C[(i & 1)][A[i]];
        C[(i & 1)][A[i]] ++;
    }
    printf("%lld\n", tot);
    return (0);
}