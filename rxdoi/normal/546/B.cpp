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

const int N=3000+19;
int A[N],n,Ans;

int main()
{
	scanf("%d",&n);
	For(i,1,n+1) scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	For(i,2,n+1)
		if (A[i-1]>=A[i]) Ans+=A[i-1]+1-A[i],A[i]=A[i-1]+1;
	printf("%d\n",Ans);
}