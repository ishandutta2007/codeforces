#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=100+19;
int Ans,n,A[Maxn],B[Maxn];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;2*i+1<=n;i++) B[i]=B[2*i+1]=B[2*i]=1;
	for (int i=1;i<=n;i++)
		if (!B[i]&&A[i]) {puts("-1");return 0;}
	for (int i=n;i>=1;i--)
	{
		int tmp=A[i];
		A[i/2]=max(A[i/2]-tmp,0);
		A[i/2*2]=max(A[i/2*2]-tmp,0);
		A[i/2*2+1]=max(A[i/2*2+1]-tmp,0);
		Ans+=tmp;
	}
	printf("%d\n",Ans);
}