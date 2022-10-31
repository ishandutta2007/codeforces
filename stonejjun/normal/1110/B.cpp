#include <bits/stdc++.h>
using namespace std;
#define inf 1e9
typedef pair<int,int> pii;
vector<int> v;
int arr[101010];
char cc[101010];
int dp[101010];

int main()
{
    long long a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z; //
    int ans=0,hap=0,dap=0,cnt=0,chk=0;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        dp[i-1]=arr[i]-arr[i-1]-1;
    }
    ans=arr[n]-arr[1]+1;
    sort(dp+1,dp+n);
    for(i=1;i<k;i++)
    {
        n--;
        ans-=dp[n];
    }
    printf("%d",ans);

}