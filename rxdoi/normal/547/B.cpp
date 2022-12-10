#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=2e5+19;
int A[N],Q[N],pre[N],suc[N],f[N];
int L,R,n;

int main()
{
	n=IN();
	For(i,1,n+1) A[i]=IN();
	Q[L=R=1]=0;
	For(i,1,n+1)
	{
		while (L<=R&&A[Q[R]]>=A[i]) R--;
		pre[i]=Q[R],Q[++R]=i;
	}
	Q[L=R=1]=n+1;
	for (int i=n;i;i--)
	{
		while (L<=R&&A[Q[R]]>=A[i]) R--;
		suc[i]=Q[R],Q[++R]=i;
	}
	For(i,1,n+1) f[suc[i]-pre[i]-1]=max(f[suc[i]-pre[i]-1],A[i]);
	for (int i=n-1;i;i--) f[i]=max(f[i],f[i+1]);
	For(i,1,n+1) printf("%d ",f[i]);puts("");
}