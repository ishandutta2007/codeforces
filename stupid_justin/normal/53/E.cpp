#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y;
int G[20][20];//
int dp[1050][1050];//ij
long long ans;
int CNT(int x)
{
	int cnt=0;
	while(x) cnt++,x-=x&(-x);
	return cnt;
}//1 
int tot;
int main()
{
	cin>>n>>m>>k;
    tot=(1<<n);
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;x--;y--;
        int u=(1<<x)|(1<<y);
		G[x][y]=G[y][x]=1;
        dp[u][u]=1;
	}
	for(int i=0;i<tot;i++) for(int j=0;j<tot;j++)
	if ((i&j)==j && dp[i][j])
	for(int k=0;k<n;k++)
    {
        int K=(1<<k);
        for(int z=0;z<n;z++)
        {
            int Z=(1<<z);
            if (G[k][z] && (i&K) && (~i&Z) && (!(((j&(~K))|Z)>>(z+1))))
            // 
            //1.
            //2.
            //3.((j&(~K))|Z) 
            //by 
            dp[i|Z][(j&(~K))|(Z)]+=dp[i][j];//(k,z)dp[i][j] 
        }
    }
    for(int i=0;i<tot;i++)
    if (CNT(i)==k) ans+=dp[tot-1][i];
    cout<<ans<<endl;

}