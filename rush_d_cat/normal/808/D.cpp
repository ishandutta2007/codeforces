#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
LL n, a[100000+10], sum;
map<LL, int> mp;
int main()
{
    scanf("%lld", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if(sum % 2)
    {
        printf("NO\n");return 0;
    }
    sum /= 2, mp[0] = 1;
    LL pre = 0;
    for(int i=1;i<=n;i++)
    {
        mp[a[i]] = 1;
        pre += a[i];
        if(pre >= sum)
        {
            if(mp[pre - sum])
            {
                printf("YES\n");
                return 0;
            }
        }
    }

    for(int i=1;i*2<=n;i++)
    {
        swap(a[i], a[n+1-i]);
    }
    
    mp.clear();
    pre = 0;
    for(int i=1;i<=n;i++)
    {
        mp[a[i]] = 1;
        pre += a[i];
        if(pre >= sum)
        {
            if(mp[pre - sum])
            {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
}