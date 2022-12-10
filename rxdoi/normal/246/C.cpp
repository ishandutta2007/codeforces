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

const int N=50+19;
int A[N],n,k;

int main()
{
	scanf("%d%d",&n,&k);
	For(i,1,n+1) scanf("%d",&A[i]);
	sort(A+1,A+n+1,greater<int>());
	for (int t=0;;t++)
		for (int i=t+1;i<=n;i++)
		{
			printf("%d ",t+1);
			For(j,1,t+1) printf("%d ",A[j]);
			printf("%d\n",A[i]);
			if (--k==0) return 0;
		}
}