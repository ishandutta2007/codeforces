// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 74;
int n, k, P[N];
int main()
{
    scanf("%d%d", &n, &k);
    if (k == 1) return !printf("3\n");
    iota(P, P + N, 0);
    for (int i = 2; i <= n; i ++)
        if (P[i] == i)
            for (int j = i; j <= n; j += i)
                P[j] -= P[j] / i;
    sort(P + 3, P + n + 1);
    long long SM = 0;
    for (int i = 0; i < k; i ++)
        SM += P[i + 3];
    return !printf("%lld\n", SM + 2);
}