#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
const double eps=1e-6;
int n,m;
double a[233333],b[233333],sum;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i],&b[i]),sum+=a[i];
	if(m>=sum)return printf("-1\n"),0;
	double l=0,r=1e16+2e13;
	while((r-l)/l>eps)
	{
		double mid=(l+r)/2,qwq=0,tot=m*mid;
		for(int i=1;i<=n;i++)
		{
			tot+=min(b[i],a[i]*mid);
			qwq+=a[i]*mid;
		}
//		cout<<l<<' '<<r<<' '<<mid<<' '<<qwq<<' '<<tot<<endl;
		if(tot>qwq)l=mid;
		else r=mid;
	}
	if(l>1e16)printf("-1\n");
	else printf("%.9lf\n",l);
	return 0;
}