#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
double R,x1,y1,x2,y2;
int main()
{
	scanf("%lf%lf%lf%lf%lf",&R,&x1,&y1,&x2,&y2);
	if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)>=R*R)
	{
		printf("%.10f %.10f %.10f\n",x1,y1,R);
		return 0;
	}
	double dis=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	if(dis==0)
	{
		printf("%.10f %.10f %.10f\n",x1+R/2,y1,R/2);
		return 0;
	}
	double x3=x2+(x1-x2)/dis*(dis+R)/2;
	double y3=y2+(y1-y2)/dis*(dis+R)/2;
	printf("%.10f %.10f %.10f\n",x3,y3,(dis+R)/2);
	return 0;
}