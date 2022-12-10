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

const int N=1e5+19;
typedef long long LL;
int A[N],B[N],n,m,top;
LL L,R,res;

bool Check(LL T)
{
	For(i,1,n+1) B[i]=A[i];top=n;
	For(i,1,m+1)
	{
		LL t=max(T-top,0LL);
		while (top&&t)
		{
			int D=min(1LL*B[top],t);
			t-=D,B[top]-=D;while (!B[top]) top--;
		}
	}
	return !top;
}

int main()
{
	n=IN(),m=IN();
	For(i,1,n+1) A[i]=IN();B[0]=1;
	while (!A[n]) n--;
	L=1,R=1e15;
	while (L<=R)
		if (Check(Mid)) res=Mid,R=Mid-1;else L=Mid+1;
	printf("%I64d\n",res);
}