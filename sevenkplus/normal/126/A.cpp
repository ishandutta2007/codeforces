#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll t1,t2,x1,x2,t0;ll y1,y2;
void upd(ll p1,ll p2)
{
	if((t1*p1+t2*p2)*(y1+y2)<(t1*y1+t2*y2)*(p1+p2)||(t1*p1+t2*p2)*(y1+y2)==(t1*y1+t2*y2)*(p1+p2)&&p1+p2>y1+y2)y1=p1,y2=p2;
}
int main()
{
	int _t1,_t2,_x1,_x2,_t0;
	scanf("%d%d%d%d%d",&_t1,&_t2,&_x1,&_x2,&_t0);
	t1=_t1,t2=_t2,x1=_x1,x2=_x2,t0=_t0;
	if(t0==t1&&t1==t2){cout<<x1<<" "<<x2<<endl;return 0;}
	if(t0==t1){cout<<x1<<" "<<0<<endl;return 0;}
	if(t0==t2){cout<<0<<" "<<x2<<endl;return 0;}
	y1=0,y2=x2;
	for(ll i=1;i<=x1;i++)
	{
		ll x=(t0-t1)*i/(t2-t0)-1;
		if(x>=0&&x<=x2&&t1*i+t2*x>=t0*(i+x))upd(i,x);x++;
		if(x>=0&&x<=x2&&t1*i+t2*x>=t0*(i+x))upd(i,x);x++;
		if(x>=0&&x<=x2&&t1*i+t2*x>=t0*(i+x))upd(i,x);x++;
		if(x>=0&&x<=x2&&t1*i+t2*x>=t0*(i+x))upd(i,x);x++;
	}
	cout<<y1<<" "<<y2<<endl;
	return 0;
}