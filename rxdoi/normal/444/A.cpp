#include<cstdio>
#include<algorithm>
using namespace std;

int A[500+19];
int n,m,x,y,z;
double Ans=0.;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	while (m--)
	{
		scanf("%d%d%d",&x,&y,&z);
		Ans=max(Ans,(A[x]+A[y])/(1.0*z));
	}
	printf("%.15lf\n",Ans);
}