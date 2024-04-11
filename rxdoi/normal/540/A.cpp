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
int n,Ans;
char A[N],B[N];

int main()
{
	n=IN();
	scanf("%s%s",A,B);
	For(i,0,n) Ans+=min(abs(A[i]-B[i]),10-abs(A[i]-B[i]));
	printf("%d\n",Ans);
}