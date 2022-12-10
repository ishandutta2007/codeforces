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

const int N=1e5+19;
int A[N],n,k,m;
long long Ans;

int main()
{
	n=IN(),k=IN();
	Ans=2*n-k-1;
	while (k--)
	{
		m=IN();
		For(i,1,m+1) A[i]=IN();
		For(i,2,m+1) if (A[i]==i&&A[i-1]==i-1) Ans-=2;else break;
	}
	printf("%I64d\n",Ans);
}