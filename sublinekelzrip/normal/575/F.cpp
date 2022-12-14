#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
long long dp[2][10010];
int qj[5010][2];
int ls[10010];
map<int,int> mp;
int fmp[10010];
int main()
{
    int n,n1,n2,t;
    cin>>n;
    cin>>t;
    ls[2*n+1]=t;
    for(n1=1;n1<=n;n1++)
    {
        cin>>qj[n1][0]>>qj[n1][1];
        ls[n1*2-1]=qj[n1][0];
        ls[n1*2]=qj[n1][1];
    }
    sort(ls+1,ls+2*n+2);
    int z=0;
    for(n1=1;n1<=2*n+1;n1++)
        if(n1==1||ls[n1]!=ls[n1-1])
        {
            z++;
            mp[ls[n1]]=z;
            fmp[z]=ls[n1];
        }
    for(n1=1;n1<=n;n1++)
    {
        qj[n1][0]=mp[qj[n1][0]];
        qj[n1][1]=mp[qj[n1][1]];
    }
    t=mp[t];
    int now=0,next=1;
    for(n1=1;n1<=z;n1++)
        if(n1!=t)
            dp[0][n1]=inf*1ll*inf;
    for(n1=1;n1<=n;n1++)
    {
        long long a=inf*1ll*inf,b=inf*1ll*inf;
        for(n2=1;n2<qj[n1][0];n2++)
        {
            a=min(a,dp[now][n2]+abs(fmp[qj[n1][0]]-fmp[n2]));
            b=min(b,dp[now][n2]-fmp[n2]);
            dp[next][n2]=a;
        }
        for(n2=qj[n1][0];n2<=qj[n1][1];n2++)
        {
            b=min(b,dp[now][n2]-fmp[n2]);
            dp[next][n2]=b+fmp[n2];
        }
        long long c=inf*1ll*inf,d=inf*1ll*inf;
        for(n2=z;n2>qj[n1][1];n2--)
        {
            c=min(c,dp[now][n2]+abs(fmp[qj[n1][1]]-fmp[n2]));
            d=min(d,dp[now][n2]+fmp[n2]);
            dp[next][n2]=c;
        }
        for(n2=qj[n1][1];n2>=qj[n1][0];n2--)
        {
            d=min(d,dp[now][n2]+fmp[n2]);
            dp[next][n2]=min(dp[next][n2],d-fmp[n2]);
        }
        swap(now,next);
    //  for(n2=1;n2<=z;n2++)
    //      cout<<n1<<' '<<fmp[qj[n1][0]]<<' '<<fmp[qj[n1][1]]<<' '<<fmp[n2]<<' '<<dp[now][n2]<<endl;
    }
    long long ans=dp[now][1];
    for(n1=2;n1<=z;n1++)
        ans=min(ans,dp[now][n1]);
    cout<<ans;          
}