#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
vector<pair<int,int>>edge;
vector<int>g[20];
int msk[310],tag[310],T[310],pos[20],n;
int getmsk()
{
	int x=0;
	rep(i,3){int y;scanf("%d",&y);x=(x<<1)+y;}
	return x;
}
int main()
{
	scanf("%d",&n);
	rep(i,n)msk[i]=getmsk();
	rep(i,n)tag[i]=getmsk();
	rep(i,n)if(i!=1)g[msk[i]].pb(i);
	pos[7]=1;
	for(;;)
	{
		bool flag=0;
		rep(i,7)if(g[i].size()&&pos[i])
		{
			for(auto j:g[i])
			{
				edge.pb(mp(pos[i],j));
				T[j]=1;
				if(!pos[tag[j]&i])pos[tag[j]&i]=j;
				flag=1;
			}
			g[i].clear();
		}
		if(!flag)break;
	}
	for(int i=0;i<3;i++)for(int j=0;j<i;j++)
	if(pos[1<<i]&&pos[1<<j]&&!pos[(1<<i)+(1<<j)]&&g[(1<<i)+(1<<j)].size())
	{
		int mk=(1<<i)+(1<<j),x=pos[1<<i],y=pos[1<<j];
		int cnt=g[mk].size();
		edge.pb(mp(x,g[mk][0]));
		edge.pb(mp(y,g[mk][0]));
		for(int k=1;k<cnt;k++)edge.pb(mp(g[mk][0],g[mk][k]));
		g[mk].clear();
	}
	rep(i,7)if(g[i].size()){puts("Impossible");return 0;}
	puts("Possible");
	rep(i,n)printf("%d%c",T[i]," \n"[i==n]);
	printf("%d\n",edge.size());
	for(auto i:edge)printf("%d %d\n",i.first,i.second);
	return 0;
}