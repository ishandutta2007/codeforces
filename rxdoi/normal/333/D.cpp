#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Mid (L+R>>1)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1000+19;
int A[N][N],vis[N][N],f[N];
int n,m,L,R,res,Time;

bool Check(int x)
{
	Time++;
	For(i,1,n+1)
	{
		*f=0;
		For(j,1,m+1) if (A[i][j]>=x) f[++*f]=j;
		For(j,1,*f) For(k,j+1,*f+1) if (vis[f[j]][f[k]]==Time) return 1;else vis[f[j]][f[k]]=Time;
	}
	return 0;
}

int main()
{
	n=IN(),m=IN();
	For(i,1,n+1) For(j,1,m+1) A[i][j]=IN();
	L=0,R=1e9;
	while (L<=R)
		if (Check(Mid)) res=Mid,L=Mid+1;else R=Mid-1;
	printf("%d\n",res);
}