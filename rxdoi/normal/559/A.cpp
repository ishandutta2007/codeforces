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

int A[7];

int sqr(int x) {return x*x;}

int main()
{
	For(i,1,7) A[i]=IN();
	printf("%d\n",sqr(A[1]+A[2]+A[3])-sqr(A[1])-sqr(A[3])-sqr(A[5]));
}