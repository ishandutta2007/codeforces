// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, p, cnt;
long long tot;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int a;
        scanf("%d", &a);
        p += (a < 0);
        if (p & 1) tot += cnt;
        else tot += i - cnt;
        cnt += (p & 1);
    }
    return !printf("%lld %lld\n", 1LL * n * (n + 1) / 2 - tot, tot);
}