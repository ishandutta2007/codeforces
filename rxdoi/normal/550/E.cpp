#include<cstdio>
#include<cstring>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=100000+19;
int A[N],n,x;

int main()
{
	scanf("%d",&n);
	For(i,1,n+1) scanf("%d",&A[i]),x+=!A[i];
	if (!A[n]&&(x!=2||A[n-1]))
	{
		puts("YES");
		For(i,1,n-1) printf("(%d->",A[i]);
		printf("%d",A[n-1]);
		For(i,1,n-1) printf(")");
		if (n!=1) printf("->0");
	} else puts("NO");
}