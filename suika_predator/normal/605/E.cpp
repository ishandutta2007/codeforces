#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<vector<double>> p(n+5,vector<double>(n+5));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			p[i][j]=x/100.0;
		}
	vector<int> vis(n+5);
	vector<double> rp(n+5,1.0);
	vector<double> dis(n+5,1.0);
	dis[n]=0.0;
	rp[n]=0.0;
	for(int tt=1;tt<=n;tt++)
	{
		double minn=1e18;
		int u=0;
		for(int i=1;i<=n;i++)
		{
			if(not vis[i] and rp[i]!=1.0 and dis[i]/(1.0-rp[i])<minn)
				u=i,minn=dis[i]/(1.0-rp[i]);
		}
		dis[u]=minn;
		vis[u]=1;
		for(int i=1;i<=n;i++)
		{
			if(not vis[i])
			{
				dis[i]+=rp[i]*p[i][u]*dis[u];
				rp[i]-=rp[i]*p[i][u];
			}
		}
	}
//	for(int i=1;i<=n;i++)cerr<<fixed<<setprecision(12)<<i<<' '<<dis[i]<<endl;
	cout<<fixed<<setprecision(12)<<dis[1]<<endl;
	return 0;
}