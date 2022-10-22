#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,f[2005],vis[2005],x[2005],y[2006],k[2005];
int cnt,edg,build[2005],conx[2005],cony[2005],lead[2005];
int G[2005][2005];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;++i){
		cin>>G[0][i];
		G[i][0]=G[0][i];
		f[i]=2e9;
	}
	for(int i=1;i<=n;++i)
		cin>>k[i];
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			G[i][j]=G[j][i]=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
		}
	}
	int sum=0;
	f[0]=0;
	for(int i=0;i<=n;++i){
		int x=n+1;
		for(int j=0;j<=n;++j)
			if(!vis[j]&&(x==n+1||f[x]>f[j])){
				x=j;
			}
		sum+=f[x];
	//	cout<<"HI "<<x<<" "<<f[x]<<endl;
		if(!lead[x]){cnt++;build[cnt]=x;}
		else{edg++;conx[edg]=x;cony[edg]=lead[x];}
		vis[x]=1;
		for(int j=0;j<=n;++j)
			if(f[j]>G[x][j]&&!vis[j]) f[j]=G[x][j],lead[j]=x;
	}
	printf("%lld\n",sum);
	cout<<cnt-1<<endl;
	for(int i=2;i<=cnt;++i)cout<<build[i]<<" ";
	cout<<endl;
	cout<<edg<<endl;
	for(int i=1;i<=edg;++i)cout<<conx[i]<<" "<<cony[i]<<endl;
	return 0;
}