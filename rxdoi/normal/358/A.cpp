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
int A[N];
int n,L,R;

int main()
{
	scanf("%d",&n);
	For(i,1,n+1) scanf("%d",&A[i]);
	For(i,1,n) For(j,1,n)
	{
		int a=min(A[i],A[i+1]),b=max(A[i],A[i+1]);
		int c=min(A[j],A[j+1]),d=max(A[j],A[j+1]);
		if (a<c&&c<b&&b<d) return puts("yes"),0;
	}
	puts("no");
}