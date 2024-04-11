#include<cstdio>
using namespace std;

const int Maxn=1e7+19;
int A[Maxn],n;

int main()
{
	scanf("%d",&n);
	for (int i=2;n;i++)
		if (!A[i])
		{
			printf("%d ",i);n--;
			for (int j=i;j<=1e7;j+=i) A[j]=1;
		}
}