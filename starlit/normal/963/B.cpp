#include<bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long ll;
int n,to[N<<1],hd[N<<1],lk[N],cnt,st[N],tot,f[N];
bool tp[N];
inline void add(int u,int v)
{to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;}
void dfs(int k)
{
	int tmp=0;
	for(int s,i=lk[k];i;i=hd[i])
    if(to[i]!=f[k])
    {
    	f[s=to[i]]=k,dfs(s);
    	tmp+=tp[s];
    }
    tp[k]=tmp&1^1;
    if(!tp[k])st[tot++]=k;
}
void dfss(int k)
{
	if(tp[k])st[tot++]=k;
	for(int s,i=lk[k];i;i=hd[i])
    if(to[i]!=f[k])
	dfss(to[i]);
}
int p;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
		scanf("%d",&p);
    	if(p)add(p,i),add(i,p);
    }
    dfs(1);
    if(!tp[1])return puts("NO"),0;
    puts("YES");
	dfss(1);
    for(int i=0;i<tot;i++)
	printf("%d\n",st[i]);
}