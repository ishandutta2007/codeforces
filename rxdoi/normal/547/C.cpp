#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int top=5e5,N=top+19;
typedef long long LL;
int p[N],vis[N],mu[N],cnt[N],A[N],pc,n,Q,x;
LL Ans;

int main()
{
	mu[1]=1;
	For(i,2,top+1)
	{
		if (!vis[i]) {p[pc++]=i,mu[i]=-1;}
		for (int j=0;j<pc&&p[j]*i<=top;j++)
		{
			vis[p[j]*i]=1;
			if (i%p[j]==0) {mu[p[j]*i]=0;break;} else mu[p[j]*i]=mu[p[j]]*mu[i];
		}
	}
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&Q);
	For(i,1,n+1) scanf("%d",&A[i]);
	while (Q--)
	{
		scanf("%d",&x);
		if (!vis[x])
		{
			for (int i=1;i*i<=A[x];i++)
				if (A[x]%i==0)
				{
					Ans+=mu[i]*(cnt[i]++);
					if (i*i!=A[x]) Ans+=mu[A[x]/i]*(cnt[A[x]/i]++);
				}
		} else
		{
			for (int i=1;i*i<=A[x];i++)
				if (A[x]%i==0)
				{
					Ans-=mu[i]*(--cnt[i]);
					if (i*i!=A[x]) Ans-=mu[A[x]/i]*(--cnt[A[x]/i]);
				}
		}
		vis[x]^=1,printf("%I64d\n",Ans);
	}
}