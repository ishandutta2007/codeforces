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
using namespace std;  
const int maxlongint=2147483647;  
const int inf=1000000000;
int num[10010],cf[10010];
int ch[110];
int nu[110],p=0;
int d[10010],dis[110][110];
queue<int> q;
int n,k,l,k1,t1,n1,n2,l1;
int dp[2000010];
int main()
{
    cin>>n>>k>>l;
    for(k1=1;k1<=k;k1++)
    {
        scanf("%d",&t1);
        num[t1]=1;
    }
    for(l1=1;l1<=l;l1++)
        scanf("%d",&ch[l1]);
    n++;
    for(n1=1;n1<=n;n1++)
        cf[n1]=num[n1]-num[n1-1];
    for(n1=1;n1<=n;n1++)
        if(cf[n1])
        {
            p++;
            nu[p]=n1;
        }
    for(n1=1;n1<=p;n1++)
    {
        for(n2=1;n2<=n;n2++)
            d[n2]=inf+1;
        d[nu[n1]]=1;
        q.push(nu[n1]);
        while(!q.empty())
        {
            n2=q.front();
            q.pop();
            for(l1=1;l1<=l;l1++)
            {
                if(n2+ch[l1]<=n&&d[n2+ch[l1]]==inf+1)
                {
                    d[n2+ch[l1]]=d[n2]+1;
                    q.push(n2+ch[l1]);
                }
                if(n2-ch[l1]>0&&d[n2-ch[l1]]==inf+1)
                {
                    d[n2-ch[l1]]=d[n2]+1;
                    q.push(n2-ch[l1]);
                }
            }
        }
        for(n2=1;n2<=p;n2++)
            dis[n1][n2]=d[nu[n2]]-1;
    }
    dp[0]=0;
    for(n1=1;n1<(1<<p);n1++)
    {
        dp[n1]=inf;
        for(int i=0;i<p;i++)
            if(n1&(1<<i))
                for(int j=i+1;j<p;j++)
                    if(n1&(1<<j))
                        dp[n1]=min(dp[n1],dis[i+1][j+1]+dp[n1-(1<<j)-(1<<i)]);
    }
    if(dp[(1<<p)-1]==inf)
        cout<<-1<<endl;
    else
        cout<<dp[(1<<p)-1]<<endl;
}