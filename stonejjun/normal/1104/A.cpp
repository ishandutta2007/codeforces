#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[101010];
int main()
{
    ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z; //
    ll sum,ans;
    scanf("%lld",&n);
    for(i=9;i>=1;i--)
    {
        if(n%i==0)
        {
            h=n/i;
            printf("%d\n",h);
            for(j=1;j<=h;j++)
            {
                printf("%d ",i);
            }
            return 0;

        }
    }
}