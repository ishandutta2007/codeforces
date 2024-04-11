#include<cstdio>
#include<functional>
#include<algorithm>
#include<cmath>
using namespace std;

const int Maxn=5000+19;
typedef double Db;
int x[Maxn],y[Maxn],z[Maxn],A,B;
Db Ans;

int main()
{
	scanf("%d",&x[0]);for (int i=1;i<=x[0];i++) scanf("%d",&x[i]);
	scanf("%d",&y[0]);for (int i=1;i<=y[0];i++) scanf("%d",&y[i]);
	scanf("%d",&z[0]);for (int i=1;i<=z[0];i++) scanf("%d",&z[i]);
	scanf("%d%d",&A,&B);
	sort(x+1,x+x[0]+1,greater<int>());
	for (int i=1;i<=y[0];i++)
		for (int j=1;j<=z[0];j++)
		{
			Db tmp=(1.0*y[i]*B*x[1]*x[1])/(1.0*y[i]*B+1.0*z[j]*A);
			if (tmp>Ans) Ans=tmp;
		}
	printf("%.12lf\n",sqrt(Ans));
}