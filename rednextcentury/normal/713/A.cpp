#include <bits/stdc++.h>
using namespace std;
int a[1000];
int ret=0;
int sol(long long x)
{
    ret=0;
    int len=0;
    while(x!=0)
    {
        a[len++]=(x%10)%2;
        x/=10;
    }
    for (int i=0;i<len;i++)
    {
        if (a[i]==1)
            ret+=(1<<(i));
    }
    return ret;
}
int s[1000000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char x;
        cin>>x;
        long long y;
        scanf("%lld",&y);
        if (x=='+')
            s[sol(y)]++;
        else if (x=='-')
            s[sol(y)]--;
        else
            printf("%d\n",s[sol(y)]);
    }
}