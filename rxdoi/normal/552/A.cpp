#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=100+19;
int A[N][N],Ans,n;

int main()
{
	n=IN();
	while (n--)
	{
		int a=IN(),b=IN(),c=IN(),d=IN();
		For(i,a,c+1) For(j,b,d+1) A[i][j]++;
	}
	For(i,1,101) For(j,1,101) Ans+=A[i][j];
	printf("%d\n",Ans);
}