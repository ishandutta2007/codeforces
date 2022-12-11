#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Rep(i,x,y) for (int i=x;i>y;i--)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e6+19,oo=(1<<30)-1;
int A[N],Rk[N],pre[N],B[N],suc[N],Q[N],C[N],vis[N];
int n,m,x,cur=1,tot,f,w,t;
long long Ans;

int cmp(int a,int b) {return A[a]<A[b];}
void Update(int x,int v) {for (int i=x;i<=n;i+=i&-i) C[i]+=v;}
int Query(int x) {int Ans=0;for (int i=x;i;i-=i&-i) Ans+=C[i];return Ans;}

int main()
{
	n=IN(),m=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,m+1)
	{
		x=IN();
		while (A[cur]!=x) Rk[++tot]=cur,cur++;B[cur++]=1;
	}
	while (cur<=n) Rk[++tot]=cur,cur++;
	sort(Rk+1,Rk+tot+1,cmp);
	Q[f=w=1]=0;A[0]=-oo;pre[0]=0;
	For(i,1,n+1)
	{
		int t=f;
		while (t>=w&&A[Q[t]]>A[i]) t--;
		pre[i]=Q[t];if (B[i]) f=t,Q[++f]=i;
	}
	Q[f=w=1]=n+1;A[n+1]=-oo;suc[n+1]=n+1;
	Rep(i,n,0)
	{
		int t=f;
		while (t>=w&&A[Q[t]]>A[i]) t--;
		suc[i]=Q[t];if (B[i]) f=t,Q[++f]=i;
	}
	For(i,1,n+1) C[i]=i&-i,vis[i]=0;
	For(i,1,tot+1)
	{
		t=Rk[i];
		Ans+=Query(suc[t]-1)-Query(pre[t]),Update(t,-1);
		vis[t]=1;
	}
	printf("%I64d\n",Ans);
}