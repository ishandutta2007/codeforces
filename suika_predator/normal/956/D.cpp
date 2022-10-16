#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iomanip>

using namespace std;
const double eps=1e-11;
struct point
{
	double x,y;
	int id;
	inline bool operator<(const point &p)const{return x==p.x?id<p.id:x<p.x;}
	inline point operator=(const point &p){x=p.x,y=p.y,id=p.id;return *this;}
}pt[233333],tmp[233333],tmp2[233333];
int n,w;
long long mergesort(int l,int r,bool fl)//fl=1:,fl=0: 
{
	if(l==r)return 0;
	int mid=(l+r)/2;
	long long ret=mergesort(l,mid,fl)+mergesort(mid+1,r,fl);
	int a=l,b=mid+1,c=l;
	while(a<=mid&&b<=r)
	{
		if(abs(pt[a].y-pt[b].y)<=eps)
		{
			if(fl)tmp[c++]=pt[b++];//,cout<<"r*\n";
			else tmp[c++]=pt[a++],ret+=b-mid-1;//,cout<<"l*\n";
		}
		else if(pt[a].y<pt[b].y)tmp[c++]=pt[a++],ret+=b-mid-1;//,cout<<"l1\n";
		else tmp[c++]=pt[b++];//,cout<<"r1\n";
	}
	while(a<=mid)tmp[c++]=pt[a++],ret+=b-mid-1;//,cout<<"l2\n";
	while(b<=r)tmp[c++]=pt[b++];//,cout<<"r2\n";
	for(int i=l;i<=r;i++)pt[i]=tmp[i];
//	cout<<"merge "<<l<<' '<<r<<' '<<fl<<' '<<ret<<endl;
	return ret;
}
double x[233333],v[233333];
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&v[i]);
		pt[i].y=v[i]/x[i];
		pt[i].x=-1.0/x[i];
		pt[i].id=i;
	}
//	cout<<fixed<<setprecision(18);
//	for(int i=1;i<=n;i++)cout<<pt[i].id<<' '<<pt[i].x<<' '<<pt[i].y<<endl;
	for(int i=1;i<=n;i++)tmp2[i]=pt[i];
	for(int i=1;i<=n;i++)pt[i]=tmp2[i],pt[i].y-=(w)*pt[i].x;
	sort(pt+1,pt+n+1);
//	for(int i=1;i<=n;i++)cout<<pt[i].id<<' '<<pt[i].x<<' '<<pt[i].y<<endl;
	long long ans=mergesort(1,n,1);
	for(int i=1;i<=n;i++)pt[i]=tmp2[i],pt[i].y+=(w)*pt[i].x;
	sort(pt+1,pt+n+1);
//	for(int i=1;i<=n;i++)cout<<pt[i].id<<' '<<pt[i].x<<' '<<pt[i].y<<endl;
	ans-=mergesort(1,n,0);
	printf("%lld\n",ans);
	return 0;
}