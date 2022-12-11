#include<cstdio>
#include<cstring>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=1e6+19;
int A[N],F[N],pre[N];
int n,cnt;

void DFS(int x)
{
	A[++cnt]=x;
	if (x>n) return;
	DFS(x*10);
	DFS(x*10+1);
}
void Out(int x)
{
	while (x)
	{
		printf("%d ",pre[x]);x-=pre[x];
	}
}

int main()
{
	scanf("%d",&n);
	DFS(1);
	memset(F,60,sizeof(F));F[0]=0;
	for (int i=1;i<=cnt;i++)
		for (int j=A[i];j<=n;j++)
			if (F[j-A[i]]+1<F[j]) F[j]=F[j-A[i]]+1,pre[j]=A[i];
	printf("%d\n",F[n]);
	Out(n);
}