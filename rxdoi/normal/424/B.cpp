#include<cstdio>
#include<cmath>
using namespace std;

const int Maxn=1000+19;
const double Eps=1e-9;
struct Point
{
	int x,y,k;
} A[Maxn];
int n,s,tot=0;
double L,R;

inline int check(double Mid)
{
	int tot=s;
	for (int i=0;i<n;i++)
		if (A[i].x*A[i].x+A[i].y*A[i].y<=Mid*Mid) tot+=A[i].k;
	return tot>=1000000;
}

int main()
{
	scanf("%d%d",&n,&s);
	for (int i=0;i<n;i++) scanf("%d%d%d",&A[i].x,&A[i].y,&A[i].k),tot+=A[i].k;
	if (tot+s<1000000) {printf("-1\n");return 0;}
	L=0.;R=1e5;
	while (R-L>Eps)
	{
		double Mid=(L+R)/2.;
		if (check(Mid)) R=Mid;else L=Mid;
	}
	printf("%.7lf\n",L);
	return 0;
}