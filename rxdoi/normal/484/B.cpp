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

const int N=2e5+19,Top=1e6+19;
int A[N],n,Ans;

int main()
{
	n=IN();
	For(i,1,n+1) A[i]=IN();
	sort(A+1,A+n+1);
	for (int i=n;i;i--)
		if (i==n||A[i]!=A[i+1])
		{
			if (Ans>A[i]-1) break;
			for (int j=A[i];j<=2e6;j+=A[i])
			{
				int t=lower_bound(A+1,A+n+1,j)-A-1;
				if (A[t]>A[i]) Ans=max(Ans,A[t]%A[i]);
			}
		}
	printf("%d\n",Ans);
}