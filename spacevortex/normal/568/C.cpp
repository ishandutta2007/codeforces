#include<bits/stdc++.h>
using namespace std;
int rc()
{
	char c=getchar();
	while(c!='C'&&c!='V') c=getchar();
	return c=='C';
}
int rd()
{
	int rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const int N=420;
int n,m,len,tot=0,cur,zs,top;
char s[N];
int t[30],bs[N],ans[N],p[N][2],dfn[N],low[N],bel[N],ins[N],stk[N],cnt[2];
vector<int> e[N];
void eadd(int u,int v)
{
	e[u].push_back(v);
}
void edel(int u)
{
	e[u].pop_back();
}
void tarjan(int x)
{
	ins[x]=1;
	stk[++top]=x;
	dfn[x]=low[x]=++cur;
	for(int v:e[x])
	{
		if(!dfn[v]) 
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(ins[v]) low[x]=min(low[x],dfn[v]);
	}
	if(low[x]>=dfn[x])
	{
		zs++;stk[top+1]=0;
		while(stk[top+1]!=x)
		{
			ins[stk[top]]=0;
			bel[stk[top]]=zs;
			top--;
		}
	}
}
bool solve()
{
	int i;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(bel,0,sizeof(bel));
	memset(ins,0,sizeof(ins));
	cur=0;zs=0;top=0;
	for(i=1;i<=tot;i++)
	{
		if(!dfn[i]) tarjan(i);
	}
	for(i=1;i<=n;i++)
	{
		if(bel[p[i][0]]==bel[p[i][1]]) return 0;
	}
	return 1;
}
int main()
{
	int i,j,x,a,y,b,st,c;
	int vis[2];
	scanf("%s",s+1);
	len=strlen(s+1);
	vis[0]=vis[1]=0;
	for(i=1;i<=len;i++) t[i]=(s[i]=='C'),vis[t[i]]=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		p[i][0]=++tot;p[i][1]=++tot;
		if(vis[0]==0) eadd(p[i][0],p[i][1]);
		if(vis[1]==0) eadd(p[i][1],p[i][0]);
	}
	for(i=1;i<=m;i++)
	{
		x=rd();a=rc();y=rd();b=rc();
		eadd(p[x][a],p[y][b]);
		eadd(p[y][b^1],p[x][a^1]);
	}
	scanf("%s",s+1);
	for(i=1;i<=n;i++) bs[i]=s[i]-'a'+1;
	st=-1;
	for(i=1;i<=n;i++)
	{
		c=t[bs[i]];
		if(bs[i]<len)
		{
			cnt[0]=cnt[1]=0;
			for(j=bs[i];j<=len;j++) cnt[t[j]]++;
			if(cnt[c]==1) eadd(p[i][c],p[i][c^1]);
			if(cnt[c^1]==0) eadd(p[i][c^1],p[i][c]);

			if(solve()==1) st=i;

			if(cnt[c]==1) edel(p[i][c]);
			if(cnt[c^1]==0) edel(p[i][c^1]);
		}
		eadd(p[i][c^1],p[i][c]);
	}
	if(solve()==1) st=n+1;
	if(st==-1)
	{
		puts("-1");
		return 0;
	}
	for(i=st;i<=n;i++) edel(p[i][t[bs[i]]^1]);
	for(i=1;i<st;i++) ans[i]=bs[i];
	if(st<=n)
	{
		c=t[bs[st]];
		cnt[0]=cnt[1]=0;
		for(j=bs[st];j<=len;j++) cnt[t[j]]++;
		if(cnt[c]==1) eadd(p[st][c],p[st][c^1]);
		if(cnt[c^1]==0) eadd(p[st][c^1],p[st][c]);
	}


	for(i=st;i<=n;i++)
	{
		vis[0]=vis[1]=0;
		for(j=(i==st?(bs[i]+1):1);j<=len;j++)
		{
			if(vis[t[j]]) continue;
			vis[t[j]]=1;
			eadd(p[i][t[j]^1],p[i][t[j]]);
			if(solve()==1)
			{
				ans[i]=j;break;
			}
			edel(p[i][t[j]^1]);
		}	
	}
	for(i=1;i<=n;i++) putchar(ans[i]+'a'-1);
	return 0;	
}