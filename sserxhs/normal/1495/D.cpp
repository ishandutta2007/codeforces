#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e2+2,p=998244353;
vector<int> lj[N];
int dis[N][N],dl[N],ans[N][N],rd[N][N],cnt[N],pre[N][N],lb[N*3][2];
int n,m,s,t,i,j,tou,wei,x,y,r;
bool ed[N];
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) scanf("%d%d",&x,&y),lj[lb[i][0]=x].push_back(lb[i][1]=y),lj[y].push_back(x);
	for (i=1;i<=m;i++) lb[i+m][0]=lb[i][1],lb[i+m][1]=lb[i][0];m<<=1;
	for (s=1;s<=n;s++)
	{
		dis[s][dl[tou=wei=1]=s]=rd[s][s]=1;
		while (tou<=wei) for (auto v:lj[x=dl[tou++]]) if (!dis[s][v]) dis[s][dl[++wei]=v]=dis[s][pre[s][v]=x]+(rd[s][v]=1); else if (dis[s][v]==dis[s][x]+1) ++rd[s][v];
	}
	for (s=1;s<=n;s++)
	{
		for (t=1;t<s;t++) printf("%d ",ans[s][t]);
		for (t=s;t<=n;t++)
		{
			for (x=t;x!=s&&rd[s][x]<=1;x=pre[s][x]);
			if (x!=s) {printf("0 ");continue;}
			for (x=t;x!=s;x=pre[s][x]) ed[x]=1;r=1;
			for (i=1;i<=m;i++) if (dis[s][lb[i][0]]+1==dis[s][lb[i][1]]&&dis[t][lb[i][0]]+1==dis[t][lb[i][1]]) ++cnt[lb[i][1]];
			for (i=1;i<=n;i++) if (!ed[i]&&i!=s) r=(ll)r*cnt[i]%p;
			memset(cnt,0,sizeof(cnt));
			for (x=t;x!=s;x=pre[s][x]) ed[x]=0;
			ans[t][s]=r;printf("%d ",r);
		}puts("");
	}
}