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

const int N=1e5+19;
int A[N],Ans,n;
long long Sum;

int main()
{
	n=IN();
	For(i,1,n+1) A[i]=IN();
	sort(A+1,A+n+1);
	For(i,1,n+1) if (Sum<=A[i]) Ans++,Sum+=A[i];
	printf("%d\n",Ans);
}