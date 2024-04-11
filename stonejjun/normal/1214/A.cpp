#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main()
{
    ll i,j,k,l,m,n,a,b,c,d,maxi=0;
    scanf("%lld %lld %lld",&n,&d,&k);
    k*=5;
    ll chk=n/d;
    ll now=chk*d;
    maxi=max(maxi,now);
    for(i=1;i<=chk;i++)
    {
        now-=d;
        while(now+k<=n) now+=k;
        maxi=max(maxi,now);
    }

    printf("%lld",n-maxi);
}