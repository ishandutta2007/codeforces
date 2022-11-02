#include <bits/stdc++.h>

int main()
{
    int N;
    long long ans = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) ans += (1ll << i);
    printf("%lld\n", ans);
}