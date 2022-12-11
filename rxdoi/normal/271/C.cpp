#include<cstdio>
using namespace std;

int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	if (n/k<3) {puts("-1");return 0;}
	for (int i=1;i<n/k;i++) 
		for (int j=1;j<=k;j++) printf("%d ",j);
	for (int j=1;j<=k;j++) printf("%d ",j%k+1);
	for (int i=0;i<n%k;i++) printf("%d ",i+1);
}