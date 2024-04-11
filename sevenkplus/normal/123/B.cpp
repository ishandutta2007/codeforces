#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b,x0,y0,x1,y1,X0,Y0,X1,Y1;
void getX(ll a,ll x,ll&X)
{
	X=x/a;
	if(X*a>=x)X--;
}
void getXY(ll a,ll b,ll x,ll y,ll&X,ll &Y)
{
	getX(a*2,x+y,X);
	getX(b*2,x-y,Y);
}
int main()
{
	int _a,_b,_x0,_y0,_x1,_y1;
	scanf("%d%d%d%d%d%d",&_a,&_b,&_x0,&_y0,&_x1,&_y1);
	a=_a,b=_b,x0=_x0,y0=_y0,x1=_x1,y1=_y1;
	getXY(a,b,x0,y0,X0,Y0);
	getXY(a,b,x1,y1,X1,Y1);
	if(X0>X1)swap(X0,X1);
	if(Y0>Y1)swap(Y0,Y1);
	if(Y1-Y0<X1-X0)swap(X0,Y0),swap(X1,Y1);
	printf("%I64d\n",Y1-Y0);
	return 0;
}