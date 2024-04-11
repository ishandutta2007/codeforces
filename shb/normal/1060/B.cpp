#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

LL N;

LL fuck(LL x)
{
    LL ret = 0;
    while(x)
    {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main()
{
    scanf("%lld",&N);
    LL tmp = 0;
    while(tmp * 10 + 9 <= N) tmp = tmp * 10 + 9;
    printf("%lld\n",fuck(tmp) + fuck(N - tmp));
}