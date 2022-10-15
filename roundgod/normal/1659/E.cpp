#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q;
bool mark[MAXN],good[31][MAXN];
int p[31][MAXN],r[31][MAXN];
void init(int n)
{
	for(int j=0;j<30;j++)
    	for(int i=0;i<n;i++)
    	{
        	p[j][i]=i;
        	r[j][i]=0;
    	}
}
int find(int id,int x)
{
    if(p[id][x]==x) return x;
    else return p[id][x]=find(id,p[id][x]);
}
void unite(int id,int x,int y)
{
    x=find(id,x);
    y=find(id,y);
    if(x==y) return;
    if(r[id][x]<r[id][y]) p[id][x]=y;
    else
    {
        p[id][y]=x;
        if(r[id][x]==r[id][y]) r[id][x]++;
    }
}
bool same(int id,int x,int y)
{
    return find(id,x)==find(id,y);
}
vector<int> tmp;
int main()
{
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		for(int j=0;j<30;j++) if(w&(1<<j)) unite(j,u,v);
		if(!(w&1)) mark[u]=mark[v]=true;
	}
	for(int i=1;i<=n;i++) 
		if(mark[i]) 
			for(int j=1;j<30;j++) good[j][find(j,i)]=true;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		bool f=false;
		for(int j=0;j<30;j++) if(same(j,u,v)) {f=true; break;}
		if(f) {puts("0"); continue;}
		for(int j=1;j<30;j++) if(good[j][find(j,u)]) {f=true; break;}
		if(f) puts("1"); else puts("2");
	}
	return 0;
}