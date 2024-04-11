#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,k;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        double x=k*sqrt(2);
        int num=n/x;
        num*=k;
        if(num*num+(num+k)*(num+k)<=n*n)
            puts("Ashish");
        else
            puts("Utkarsh");
    }
    return 0;
}