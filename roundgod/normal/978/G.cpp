#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s[MAXN],d[MAXN],c[MAXN],ans[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&s[i],&d[i],&c[i]);
		ans[d[i]]=m+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]) continue;
		int res=INF,t=-1;
		for(int j=1;j<=m;j++) 
			if(c[j] && s[j]<=i&&i<d[j]&&d[j]<res) res=d[j],t=j;
		if(res<INF) ans[i]=t,c[t]--;
	}
	for(int i=1;i<=m;i++) if(c[i]) {puts("-1"); return 0;}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}