#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=x*10+c-'0';return x;
}

const int N=100000+19;
int A[N],B[N],n,m,Max;

int main()
{
	n=IN(),m=IN();
	For(i,1,m+1) A[i]=IN(),B[i]=IN(),Max=max(Max,B[i]);
	For(i,1,m) if (A[i+1]-A[i]<abs(B[i]-B[i+1])) return puts("IMPOSSIBLE"),0;
	Max=max(Max,B[1]+abs(A[1]-1));
	Max=max(Max,B[m]+abs(A[m]-n));
	For(i,1,m)
	{
		int tmp=(A[i+1]-A[i])-abs(B[i]-B[i+1]);
		Max=max(Max,max(B[i],B[i+1])+tmp/2);
	}
	printf("%d\n",Max);
}