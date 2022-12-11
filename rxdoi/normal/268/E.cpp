#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=50000+19;
struct note {int l,p;} A[Maxn];
int n;
double Ans,x;

inline int cmp(note i,note j)
{
	return (100-j.p)*(i.p*i.l)>(100-i.p)*(j.p*j.l);
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&A[i].l,&A[i].p);
	sort(A,A+n,cmp);
	for (int i=0;i<n;i++)
	{
		Ans+=A[i].p/100.*A[i].l+(100-A[i].p)/100.*(x+A[i].l);
		x+=A[i].p/100.*A[i].l;
	}
	printf("%.10lf\n",Ans);
}