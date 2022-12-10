#include<cstdio>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=60;
typedef long long LL;
LL f[N],k;
int n;

void DFS(int x)
{
	if (x>n) return;
	if (k>f[n-x]) k-=f[n-x],printf("%d %d ",x+1,x),DFS(x+2);
		else printf("%d ",x),DFS(x+1);
}

int main()
{
	scanf("%d%I64d",&n,&k);
	f[0]=f[1]=1;
	For(i,2,n+1) f[i]=f[i-1]+f[i-2];
	DFS(1);
	puts("");
}