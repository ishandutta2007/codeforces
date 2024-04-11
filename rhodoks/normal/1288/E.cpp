#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 610000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int bit[MAXN];
int n,m;
int lowbit(int x)
{
	return x&-x;
}

void add(int x,int a)
{
	for (;x<=n+m;x+=lowbit(x))
		bit[x]+=a;
}

int query(int x)
{
	int ans=0;
	for (;x;x-=lowbit(x))
		ans+=bit[x];
	return ans;
}

int id[MAXN],pos[MAXN],ans[MAXN];
bool visit[MAXN];
int main()
{
	int x;
	cin>>n>>m;
	for (int i=n;i;i--)
	{
		id[i]=n-i+1;
		pos[id[i]]=i;
		add(i,-1);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		id[n+i]=x;
		add(pos[x]+1,1);
		add(n+i,-1);
		ans[x]=max(ans[x],n+1+query(pos[x]));
		id[pos[x]]=0;
		pos[x]=n+i;
		visit[x]=1;
	}
	for (int i=1;i<=n+m;i++)
		if (id[i])
			ans[id[i]]=max(ans[id[i]],n+1+query(i));
	for (int i=1;i<=n;i++)
	{
		if (visit[i])
			printf("1 ");
		else
			printf("%d ",i);
		printf("%d\n",ans[i]);
	}
	return ~~(0^_^0);
}