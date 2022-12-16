#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=510,inf=1e9+7;
	int n1,n2,m,r,b,st,ed,stt,edd,tot;
	int ans1,ans2;
	char s1[N],s2[N];
	int c[N];
	int head[N],cnt=1;
	struct point
	{
		int nxt,to,f,c;
	}a[N*N];
	inline void link(int x,int y,int l,int r,int v)
	{
		c[x]-=l,c[y]+=l;
		a[++cnt]=(point){head[x],y,r-l,v};head[x]=cnt;
		a[++cnt]=(point){head[y],x,0,-v};head[y]=cnt;
	}
	int dis[N],pre[N],flow[N],eg[N];
	bool vis[N];
	queue<int> q;
	inline bool spfa()
	{
		memset(flow,0x3f,sizeof(flow));
		memset(dis,0x3f,sizeof(dis));dis[stt]=0;
		memset(vis,0,sizeof(vis));vis[stt]=1;
		pre[edd]=0;
		q.push(stt);
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			for(int i=head[now];i;i=a[i].nxt)
			{
				if(!a[i].f) continue;
				int t=a[i].to;
				if(dis[t]>dis[now]+a[i].c)
				{
					dis[t]=dis[now]+a[i].c;
					flow[t]=min(flow[now],a[i].f);
					pre[t]=now;
					eg[t]=i;
					if(!vis[t])
					{
						q.push(t);
						vis[t]=0;
					}
				}
			}
		}
		return pre[edd];
	}
	inline void main()
	{
		n1=read(),n2=read(),m=read(),r=read(),b=read();
		st=n1+n2+1,ed=st+1;
		stt=ed+1,edd=stt+1;
		scanf("%s%s",s1+1,s2+1);
		for(int x,y,i=1;i<=m;++i)
		{
			x=read(),y=read();
			link(x,y+n1,0,1,r);
			link(y+n1,x,0,1,b);
		}
		for(int i=1;i<=n1;++i)
		{
			if(s1[i]=='R') link(st,i,1,inf,0);
			else if(s1[i]=='B') link(i,ed,1,inf,0);
			else
			{
				link(st,i,0,inf,0);
				link(i,ed,0,inf,0);
			}
		}
		for(int i=1;i<=n2;++i)
		{
			if(s2[i]=='R') link(i+n1,ed,1,inf,0);
			else if(s2[i]=='B') link(st,i+n1,1,inf,0);
			else
			{
				link(st,i+n1,0,inf,0);
				link(i+n1,ed,0,inf,0);
			}
		}
		link(ed,st,0,inf,0);
		for(int i=1;i<=ed;++i)
		{
			if(c[i]>0) tot+=c[i],link(stt,i,0,c[i],0);
			if(c[i]<0) link(i,edd,0,-c[i],0);
		}
		while(spfa())
		{
			ans1+=flow[edd]*dis[edd];
			ans2+=flow[edd];
			int now=edd;
			while(now!=stt)
			{
				a[eg[now]].f-=flow[edd];
				a[eg[now]^1].f+=flow[edd];
				now=pre[now];
			}
		}
		if(ans2!=tot) return(void)puts("-1");
		printf("%lld\n",ans1);
		for(int i=2;i<=4*m+1;i+=4)
		{
			if(!a[i].f) putchar('R');
			else if(!a[i+2].f) putchar('B');
			else putchar('U');
		}
	}
}
signed main()
{
	red::main();
	return 0;
}