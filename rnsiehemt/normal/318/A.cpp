#include <cstdio>

typedef long long ll;

ll N, K;

int main()
{
    scanf("%I64d%I64d", &N, &K);
    if (N%2ll) N++;
    if (K <= N/2) printf("%I64d\n", K*2ll-1ll);
    else printf("%I64d\n", 2ll*(K-N/2ll));
}