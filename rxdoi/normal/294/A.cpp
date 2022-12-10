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

const int N=100+19;
int A[N],n,Q,x,y;

int main()
{
	n=IN();
	For(i,1,n+1) A[i]=IN();
	for (Q=IN();Q--;)
	{
		x=IN(),y=IN();
		A[x-1]+=y-1,A[x+1]+=A[x]-y;A[x]=0;
	}
	For(i,1,n+1) printf("%d\n",A[i]);
}