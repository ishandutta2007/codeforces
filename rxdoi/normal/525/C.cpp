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

const int N=1e6+19;
long long Ans;
int A[N],n,t,x;

int main()
{
	n=IN();
	For(i,0,n) A[i]=IN();
	sort(A,A+n);
	for (int i=n-1;i>=0;i--)
		if (A[i-1]>=A[i]-1)
			if (x) Ans+=1LL*x*(A[i-1]),x=0,i--;else x=A[i-1],i--;
	printf("%I64d\n",Ans);
}