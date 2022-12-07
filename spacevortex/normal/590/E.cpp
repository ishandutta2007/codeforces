#include<bits/stdc++.h>
#define pb push_back
#define lb(x) ((x)&(-x))
using namespace std;
const int N=1e7+50,P=760,E=P*P*2+P*10;
int n,tot=0,cur=0,m,top=0,tim=0;
char s[N];
vector<int> sl[P];
int nxt[N][2],fail[N],id[N],f[P][P],pl[P],pr[P],h[P],tag[N],lvis[N],stk[N];
queue<int> que;
vector<int> e[N];
int mat[P],vis[P];
bool find(int x)
{
	int i;
	vis[x]=1;
	for(i=1;i<=n;i++)
	{
		if(f[x][i]==0) continue;
		if((!mat[i])||(vis[mat[i]]==0&&find(mat[i])==1))
		{
			mat[i]=x;return 1;
		}
	}
	return 0;
}
int main()
{
	int i,j,len,now,c,x,a,b,nid;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		now=0;
		for(j=1;j<=len;j++)
		{
			c=s[j]-'a';
			if(!nxt[now][c]) nxt[now][c]=++tot;
			now=nxt[now][c];
			sl[i].pb(now);
		}
		id[i]=now;tag[now]=i;
	}
	for(i=0;i<2;i++) if(nxt[0][i]) que.push(nxt[0][i]);
	while(!que.empty())
	{
		x=que.front();que.pop();
		stk[++top]=x;
		for(i=0;i<2;i++)
		{
			if(nxt[x][i]) fail[nxt[x][i]]=nxt[fail[x]][i],que.push(nxt[x][i]);
			else nxt[x][i]=nxt[fail[x]][i];
		}
	}
	for(i=1;i<=top;i++)
	{
		x=stk[i];
		if(!tag[fail[x]]) fail[x]=fail[fail[x]];
	}
	for(i=1;i<=n;i++)
	{
		tim++;
		for(int w:sl[i])
		{
			x=w;
			while(x)
			{
				if(tag[x])
				{
					nid=tag[x];
					if(lvis[x]==tim) break;
					//printf("U%d %d\n",nid,i);
					lvis[x]=tim;
					if(nid!=i) f[nid][i]=1;
				}
				x=fail[x];
			}
		}
	}
	
	for(i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		find(i);
	}
	
	m=0;
	for(i=1;i<=n;i++)
	{
		if(mat[i]) pl[i]=mat[i],pr[mat[i]]=i;
	}
	for(i=1;i<=n;i++) if(pl[i]==0) h[++m]=i;
	//printf("M%d\n",m);
	//for(i=1;i<=n;i++) printf("#%d %d\n",i,mat[i]);

	
	while(true)
	{
		a=b=0;
		for(i=1;i<=m&&a==0;i++)
		{
			for(j=1;j<=m&&a==0;j++)
			{
				if(f[h[i]][h[j]]) {a=i;b=j;}	
			}
		}
		if(a==0) break;
		while(f[h[a]][h[b]]) h[a]=pr[h[a]];
	}
	printf("%d\n",m);
	//------------------------------------------------------------------------------------------------
	for(i=1;i<=m;i++) printf("%d ",h[i]);
	return 0;
}