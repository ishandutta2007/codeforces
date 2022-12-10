#include<cstdio>
#include<cctype>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
typedef long long LL;
int A[N],B[N],n;
LL Ans;

int main()
{
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) B[i]=IN();
	For(i,1,n+1)
	{
		int x=B[i]/2,y=B[i]-x;
		if (x<1||y<1||x>A[i]||y>A[i]) {Ans--;continue;}
			else Ans+=1LL*x*y;
	}
	printf("%I64d\n",Ans);
}