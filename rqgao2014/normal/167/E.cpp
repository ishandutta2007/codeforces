#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>
#define ll long long
using namespace std;

int dp[1001];
int n,m,p,rd[1001],cd[1001],tot,sink[1001],source[1001];
ll a[1001][1001];
vector<int> g[1001];

int dfs(int x){
	if(dp[x]!=-1) return dp[x];
	ll ans=0;
	for(int i=0;i<g[x].size();i++){
		ans+=dfs(g[x][i]);
		if(ans>=p) ans-=p;
	}
	return dp[x]=ans;
}
ll exp(ll x,int y){
	if(!y) return 1;
	ll ans=exp(x,y/2);
	ans=ans*ans;
	ans%=p;
	if(y&1) ans=(ans*x)%p;
	return ans;
}

ll gauss(){
	ll ans=1,tmp=1;
	for(int i=1;i<tot;i++)
	{
		bool isok=false;
		int t=i;
		for(int j=i;j<=tot;j++)
			if(a[j][i]){t=j;isok=true;break;}
		if(!isok) return 0;
		for(int j=i;j<=tot;j++)
			swap(a[i][j],a[t][j]);
		if(t!=i) tmp=-tmp;
		for(int j=i+1;j<=tot;j++)
			{
				ll k=(p-a[j][i])*exp(a[i][i],p-2)%p;
				for(int t=i;t<=tot;t++)
					a[j][t]=(a[j][t]+a[i][t]*k)%p;
			}
	}
	/*for(int i=1;i<=tot;i++){
		for(int j=1;j<=tot;j++)
			printf("%d ",a[i][j]);
		puts("");
	}*/
	for(int i=1;i<=tot;i++) ans=(ans*a[i][i])%p;
	ans=ans*tmp;
	return (p+ans)%p;
}

int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		cd[x]++;
		rd[y]++;
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(cd[i]>0&&rd[i]==0){
			tot++;
			source[tot]=i;
		}
	tot=0;
	for(int i=1;i<=n;i++)
		if(rd[i]>0&&cd[i]==0){
			tot++;
			sink[tot]=i;
		}
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=n;j++) dp[j]=-1;
		dp[source[i]]=1;
		for(int j=1;j<=tot;j++)
			a[i][j]=dfs(sink[j]);
	}
	/*for(int i=1;i<=tot;i++){
		for(int j=1;j<=tot;j++)
			printf("%d ",a[i][j]);
		puts("");
	}*/
	ll ans=gauss();
	//cout<<ans<<endl; 
	for(int i=1;i<=n;i++)
		if(rd[i]==0&&!cd[i]){
			int p1,q;
			p1=q=0;
			for(int j=1;j<=tot;j++) if(sink[j]<i) p1++;
			for(int j=1;j<=tot;j++) if(source[j]<i) q++;
			if(p1%2!=q%2) ans=-ans;
		}
	if(ans<0) ans+=p;
	printf("%d\n",(int)(ans));
	return 0;
}