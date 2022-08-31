#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int m;
struct opts
{
	int kind,l,c;
	opts(int K=0,int L=0,int C=0){kind=K;l=L;c=C;}
}opt[100005];
long long b[100005];
long long last[100005];
struct Node
{
	int num,l,c;
	Node(int N=0,int L=0,int C=0){num=N;l=L;c=C;}
}a[100005];
int G[100005],T,n;


int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int kind;
		scanf("%d",&kind);
		if(kind==1)
		{
			int x;
			scanf("%d",&x);
			opt[i]=opts(kind,x,0);
			last[i]=last[i-1]+1;
			if(T>100000)continue;
			G[++T]=x;
		}else
		{
			int l,c;
			scanf("%d%d",&l,&c);
			opt[i]=opts(kind,l,c);
			last[i]=last[i-1]+1ll*l*c;
			if(T>100000)continue;
			for(int i=1;i<=c;i++)
			{
				int delta=min(100000,T+l);
				int Pt=T;
				for(int j=1;j<=delta-Pt;j++)
				{
					G[++T]=G[j];
					if(T>=100000)break;
				}
				if(T>=100000)break;
			}
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&b[i]);
	for(int i=1,top=1;i<=m&&top<=n;i++)
	{
		while(last[i]>=b[top]&&top<=n)
		{
			if(opt[i].kind==1)
			{
				printf("%d ",opt[i].l);
			}else
			{
				long long del=b[top]-last[i-1];
				del%=opt[i].l;
				if(!del)del=opt[i].l;
				printf("%d ",G[del]);
			}
			top++;
		}
	}
	return 0;
}