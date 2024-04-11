// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
int q;
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        long long n;
        scanf("%lld", &n);
        if (n <= 14)
        {
            printf("NO\n");
            continue;
        }
        n %= 14;
        if (1 <= n && n <= 6)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}