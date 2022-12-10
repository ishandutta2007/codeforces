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

const int N=1000+19;
int A[N],Max,n;

int main()
{
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1)
	{
		int tmp=1;
		for (int j=i-1;j;j--) if (A[j]<=A[j+1]) tmp++;else break;
		for (int j=i+1;j<=n;j++) if (A[j]<=A[j-1]) tmp++;else break;
		Max=max(Max,tmp);
	}
	printf("%d\n",Max);
}