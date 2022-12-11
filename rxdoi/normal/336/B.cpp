#include<cstdio>
#include<cmath>
using namespace std;

const int M=100000+19;
int m,R;
double F[M],Ans=0.;

inline double Dis(int x)
{
	if (x==0) return double(R)*2.;
	if (x==1) return double(R)*2.+sqrt(2.)*R;
	if (x>=2) return double(R)*2.*double((sqrt(2.)+(x-1.)));
}

int main()
{
	scanf("%d%d",&m,&R);
	for (int i=0;i<m;i++) F[i]=(i?F[i-1]:0.)+Dis(i);
	for (int i=0;i<m;i++) Ans+=F[i]+F[m-i-1]-F[0];
	printf("%.10lf\n",Ans/m/m);
	return 0;
}