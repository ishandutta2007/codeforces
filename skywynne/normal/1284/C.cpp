// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, m, q, A[N];
int main()
{
    scanf("%d%d", &n, &m);
    A[0] = 1;
    for (int i = 1; i <= n; i ++)
        A[i] = 1LL * A[i - 1] * i % m;
    int tot = 0;
    for (int i = 1; i <= n; i ++)
    {
        tot = (tot + 1LL * (n - i + 1) * (n - i + 1) % m * A[n - i] % m * A[i]) % m;
    }
    return !printf("%d\n", tot);
    return 0;
}