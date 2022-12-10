#include<cstdio>
#include<cctype>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=2e6+19;
int A[N],n;
long long Ans;

int main()
{
	n=IN();
	For(i,0,n) A[i]=IN();
	sort(A,A+n,greater<int>());
	for (int i=0;1<<(2*i)<=n;i++)
		For(j,0,n/(1<<(2*i))) Ans+=A[j];
	printf("%I64d\n",Ans);
}