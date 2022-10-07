#include<bits/stdc++.h>
using namespace std;
int p[509][509];
int rmq[509][509][16];
int t=0;
int n,m,K,q;
int RMQ(int a, int b)
{
    return max(max(rmq[a][b][t],rmq[a][b+K-(1<<t)][t]),max(rmq[a+K-(1<<t)][b][t],
                                                          rmq[a+K-(1<<t)][b+K-(1<<t)][t]));
}
int bruteforce()
{
    int ans=1000000008;
    for (int i=0; i<=n-K; i++)
        for (int j=0; j<=m-K; j++)
    {int S=0;
        for (int r=i; r<i+K; r++)
            for (int t=j; t<j+K;t++)
            S=max(S,p[r][t]);
        ans=min(ans,S);
    }
    return ans;
}
main()
{
int ans=1000000008;
cin>>n>>m>>K>>q;
//if(K==1) ans=bruteforce(); else{
while((1<<(t+1))<=K) t++;
for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
    p[i][j]=1000000007;
for (int i=0; i<q; i++)
{int x,y,t;
cin>>x>>y>>t;
p[x-1][y-1]=min(p[x-1][y-1],t);
}

for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
    rmq[i][j][0]=p[i][j];
for(int i=1; i<=t; i++)
for (int j=0; j<=n-(1<<i); j++)
    for (int k=0; k<=m-(1<<i); k++)
   {
       rmq[j][k][i]=max(rmq[j][k][i-1],
                     max(rmq[j+(1<<(i-1))][k][i-1],
                    max(rmq[j][k+(1<<(i-1))][i-1],
                        rmq[j+(1<<(i-1))][k+(1<<(i-1))][i-1])));



   }

for (int i=0; i<=n-K; i++)
        for (int j=0; j<=m-K; j++)
{
       ans=min(ans,RMQ(i,j));
       //cout<<i<<" "<<j<<" "<<RMQ(i,j)<<endl;
        }
//cout<<ans<<" "<<bruteforce()<<endl;
if(ans>1000000000)
 cout<<-1<<endl;
 else cout<<ans<<endl;
return 0;
}