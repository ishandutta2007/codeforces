// Educational Codeforces Round 10, Problem E
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143
	
const int maxn=300005;

int N,M,o,top,tot,Flag,U,V;
vector<PII> f[maxn];
vector<int> G[maxn];
int x[maxn],y[maxn],z[maxn],where[maxn],dfn[maxn],low[maxn],stack[maxn],fa[maxn],has[maxn];
set<PII> stg;

void dfs(int s,int fa)
{
	++o,dfn[s]=o,low[s]=o;
	++top,stack[top]=s;
	for (int i=0;i<f[s].size();i++)
		if (f[s][i].w1!=fa)
		{
			int cs=f[s][i].w1;
			if (dfn[cs]==0)
			{
				dfs(cs,s);
				low[s]=min(low[s],low[cs]);
			}
			else
				low[s]=min(low[s],dfn[cs]);
		}
	if (dfn[s]==low[s])
	{
		++tot;
		while (true)
		{
			where[stack[top]]=tot;
			low[stack[top]]=maxlongint;
			if (stack[top]==s) break;
			--top;
		}
		--top;
	}
}

void dfs2(int s,int father)
{
	fa[s]=father;
	for (int i=0;i<G[s].size();i++)
		if (G[s][i]!=father) dfs2(G[s][i],s);
}

bool findedge(int x,int y)
{
	//cout<<x<<" "<<y<<endl;
	PII ls=m_p(x,y);
	set<PII>::iterator lsg=stg.l_b(ls);
	if (lsg!=stg.end())
		if (*lsg==ls) return true;
	ls=m_p(y,x);
	lsg=stg.l_b(ls);
	if (lsg!=stg.end())
		if (*lsg==ls) return true;
	return false;
}

int main()
{
	//freopen("E.in","r",stdin);
	
	scanf("%d %d",&N,&M);
	for (int i=1;i<=M;i++)
	{
		scanf("%d %d %d",&x[i],&y[i],&z[i]);
		f[x[i]].p_b(m_p(y[i],z[i]));
		f[y[i]].p_b(m_p(x[i],z[i]));
	}
	scanf("%d %d",&U,&V);
	o=0;
	memset(where,0,sizeof(where));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	top=0;
	tot=0;
	for (int i=1;i<=N;i++)
		if (dfn[i]==0) dfs(i,0);
	
	//for (int i=1;i<=N;i++) cout<<where[i]<<" ";cout<<endl;
		
	memset(has,0,sizeof(has));
	for (int i=1;i<=M;i++) 
		if (where[x[i]]==where[y[i]]) has[where[x[i]]]|=z[i]; else 
		{
			if (z[i]==1) stg.insert(m_p(where[x[i]],where[y[i]]));
			G[where[x[i]]].p_b(where[y[i]]);
			G[where[y[i]]].p_b(where[x[i]]);
		}
	memset(fa,0,sizeof(fa));
	U=where[U],V=where[V];
	dfs2(U,0);
	
	Flag=1;
	while (V!=0)
	{
		if (has[V]==1) Flag=0;
		if (fa[V]!=0)
			if (findedge(fa[V],V)) Flag=0;
		V=fa[V];
	}	
	if (Flag==1) cout<<"NO"<<endl; else cout<<"YES"<<endl;
		
		
	return 0;
}