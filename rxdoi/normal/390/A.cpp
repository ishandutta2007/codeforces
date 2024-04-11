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

const int N=1e5+19,T=109;
int A[T],B[T],n,AA,AB;

int main()
{
	n=IN();
	For(i,0,n) A[IN()]++,B[IN()]++;
	For(i,0,T) AA+=A[i]>0;
	For(i,0,T) AB+=B[i]>0;
	printf("%d\n",min(AA,AB));
}