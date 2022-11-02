#include<bits/stdc++.h>
using namespace std;
typedef double db;
const db eps=1e-8;
int a,b,c,t;
struct pt{
	db x,y;
	inline void rd(){
		scanf("%lf%lf",&x,&y);
	}
}A,B,v[4];
inline db get(int x,bool d){
	if(d)return (-(db)x*a-c)/b;
	return (-(db)x*b-c)/a;
}
inline void ins(db x,db y){
	for(int i=0;i<t;i++)
	if(fabs(v[i].x-x)<eps&&fabs(v[i].y-y)<eps)return;
	v[t++]={x,y};
}
db tp,ans,xx,yy;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	A.rd(),B.rd();
	if(a==0||b==0){
		printf("%.7lf",fabs(A.x-B.x)+fabs(A.y-B.y));
		return 0;
	}
	if(A.y>B.y)swap(A,B);ans+=B.y-A.y;
	tp=get(A.x,1);
	if(tp>=A.y&&tp<=B.y)ins(A.x,tp);
	tp=get(B.x,1);
	if(tp>=A.y&&tp<=B.y)ins(B.x,tp);
	if(A.x>B.x)swap(A,B);ans+=B.x-A.x;
	tp=get(A.y,0);
	if(tp>=A.x&&tp<=B.x)ins(tp,A.y);
	tp=get(B.y,0);
	if(tp>=A.x&&tp<=B.x)ins(tp,B.y);
	if(t>1){
		xx=v->x-(v+1)->x,yy=v->y-(v+1)->y;
		if((xx*yy<0)==((A.x-B.x)*(A.y-B.y)<0))
		ans+=sqrt(xx*xx+yy*yy)-fabs(xx)-fabs(yy);
	}printf("%.7lf",ans);
}