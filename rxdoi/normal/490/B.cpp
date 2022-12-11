#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=2e5+19,V=1e6+19;
int A,B,pre[V],nxt[V],t1[V],t0[V],Ans[Maxn],n,fir,sec,x;

int main()
{
	scanf("%d",&n);
	memset(t1,-1,sizeof(t1));
	memset(t0,-1,sizeof(t0));
	for (int i=1;i<=n;i++) scanf("%d%d",&A,&B),nxt[A]=B,pre[B]=A,t0[A]=0,t1[B]=0;
	for (int i=1;i<=1e6+1;i++) 
	{
		if (t0[i]==0&&t1[i]==-1) fir=i;
		if (t0[i]==-1&&t1[i]==0) sec=i;
	}
	Ans[1]=x=fir;
	for (int i=3;i<=n;i+=2) Ans[i]=nxt[x],x=nxt[x];
	if (n%2==0)
	{
		Ans[n]=x=sec;
		for (int i=n-2;i>=1;i-=2) Ans[i]=pre[x],x=pre[x];
	} else
	{
		x=0;
		for (int i=2;i<=n;i+=2) Ans[i]=nxt[x],x=nxt[x];
	}
	for (int i=1;i<=n;i++) printf("%d ",Ans[i]);puts("");
}