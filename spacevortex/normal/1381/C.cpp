#include<bits/stdc++.h>
#define pb push_back
#define cle(a,b) memset(a,0,sizeof(int)*(b))
using namespace std;
struct Node
{
	int c,w;
	bool operator <(const Node &a)const
	{
		return w<a.w;
	}
};
priority_queue<Node> prq;
const int N=3e5+50;
int n,m,X,Y,w,num;
int a[N],f[N],cnt[N],b[N];
vector<int> s[N];
Node p[10];
int pos[10];
bool solve(int tot,int op)
{
	//printf("solve %d %d\n",tot,op);
	int i,c;
	m-=tot;
	for(i=1;i<=tot;i++)
	{
		if(prq.empty()) return 0;
		p[i]=prq.top();prq.pop();
		c=p[i].c;
		pos[i]=s[c].back();
		s[c].pop_back();
	}
	pos[tot+1]=pos[1];
	//for(i=1;i<=tot;i++) printf("#%d %d\n",i,pos[i]);
	for(i=1;i<=tot;i++) b[pos[i]]=a[pos[i+1]];
	for(i=1;i<=tot;i++) if(p[i].w>=2) prq.push((Node){p[i].c,p[i].w-1});
	if(op) b[pos[1]]=w,m++;
	return 1;
}
void Solve()
{
	int i;
	
	scanf("%d%d%d",&n,&X,&Y);
	while(!prq.empty()) prq.pop();
	cle(cnt,n+5);
	for(i=1;i<=n;i++) b[i]=-1;
	m=Y-X;
	for(i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
	w=1;
	while(cnt[w]) w++;
	num=0;
	for(i=1;i<=n+1;i++)
	{
		s[i].clear();
		if(cnt[i])
		{
			num++;
			prq.push((Node){i,cnt[i]});
		}
	}
	for(i=1;i<=n;i++) s[a[i]].pb(i);
	if(m>=3&&(m&1)&&num>=3) solve(3,0);
	if(m&1)
	{
		if(Y==n)
		{
			puts("NO");
			return ;
		}
		if(solve(2,1)==0)
		{
			puts("NO");return ;
		}
	}
	while(m>=2) 
	{
		if(solve(2,0)==0)
		{
			puts("NO");return ;
		}
	}
	//for(i=1;i<=n;i++) printf("%d ",b[i]);putchar('\n');
	for(i=1;i<=n;i++)
	{
		if(b[i]==-1)
		{
			if(X)
			{
				X--;b[i]=a[i];
			}
			else b[i]=w;
		}
	}
	puts("YES");
	for(i=1;i<=n;i++) printf("%d ",b[i]);
	putchar('\n');
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) Solve();
	return 0;
}