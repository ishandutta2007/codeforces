#include<cstdio>
using namespace std;

const int Maxn=50+19;
int A[Maxn],B[Maxn],n,m,Max,cnt;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d",&B[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (B[j]%A[i]==0)
			{
				if (B[j]/A[i]>Max) Max=B[j]/A[i],cnt=1;
					else if (B[j]/A[i]==Max) cnt++;
			}
	printf("%d\n",cnt);
}