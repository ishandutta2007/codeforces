#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
#define ll long long
using namespace std;

const double pi=3.1415926535898,eps=1e-13;
struct node{
	int x,y;
}p[100005];
int n,xx,yy;
double s1,s2;

inline bool cmp(node a,node b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
inline ll check(node a,node b,node c){
	return (ll)(a.x-b.x)*(c.y-b.y)-(ll)(a.y-b.y)*(c.x-b.x);
}
inline double dis(double a,double b,double x,double y){
	return sqr(a-x)+sqr(b-y);
}

int main(){
	scanf("%d%d%d",&n,&xx,&yy);
	s1=1e15;
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		p[i].x=x;p[i].y=y;
		s2=max((double)sqr((double)(x-xx))+sqr((double)(y-yy)),s2);
	}
	for(int i=1;i<=n;i++){
		double l=0.0,r=1.0,x=p[i].x,y=p[i].y,s=p[i%n+1].x,t=p[i%n+1].y;
		while(l+eps<r){
			double mid=(l+r)/2.0,midd=(mid+r)/2.0;
			if(dis(xx,yy,mid*x+s*(1.0-mid),mid*y+t*(1.0-mid))>dis(xx,yy,midd*x+s*(1.0-midd),midd*y+t*(1.0-midd))) l=mid; else r=midd;
		}
		s1=min(s1,dis(xx,yy,r*x+s*(1.0-r),r*y+t*(1.0-r)));
	}
	printf("%.13f\n",(s2-s1)*pi);
	return 0;
}
/*
4 1 -1
0 0
1 2
2 0
1 1
*/