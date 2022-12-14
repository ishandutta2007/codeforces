#include <bits/stdc++.h>
using namespace std;
map<long long,int> mp;
int main ()
{
    for (long long i=1;i<=1000000;i++)
        mp[i*i*i]=i;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b;

    scanf("%lld",&a);
    scanf("%lld",&b);
        if (mp.count(a*b))
        {
            long long x = mp[a*b];
            if (a%x==0 && b%x==0)
                printf("Yes\n");
            else printf("No\n");
        }
        else printf("No\n");
    }
}