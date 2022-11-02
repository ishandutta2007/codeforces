#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;

ll ans[1010][1010];

int main()
{
    ll i,j,k,l,m,n,x=1,y=1;
    scanf("%lld",&n);
    m=(n/2)*(n/2);
    for(i=0;i<n*n;i+=4)
    {
        ans[x][y]=i;
        ans[x][y+1]=i+1;
        ans[x+1][y]=i+2;
        ans[x+1][y+1]=i+3;
        y+=2;
        if(y>n)
        {
            x+=2;
            y=1;
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%lld ",ans[i][j]);
        }
        printf("\n");
    }
}