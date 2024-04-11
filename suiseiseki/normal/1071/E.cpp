#include<bits/stdc++.h>
int cmp(double x,double eps=1e-7){
	return x<-eps?-1:x>eps;
}
const int Maxn=100000;
struct Node{
	double x,y;
	Node(double _x=0,double _y=0){
		x=_x,y=_y;
	}
	friend Node operator -(const Node &a,const Node &b){
		return Node(a.x-b.x,a.y-b.y);
	}
};
Node a[Maxn+5];
double t[Maxn+5];
int n;
double w,h,e_1,e_2;
double x_of_y(const Node &p_1,const Node &p_2,const double &y){
	Node d=p_2-p_1;
	return p_1.x+d.x/d.y*(y-p_1.y);
}
Node p_0,p_1;
double l;
double fix(double x){
	double x_0=x_of_y(p_0,Node(x,h),p_1.y);
	if(cmp(std::abs(x_0-p_1.x)-l)<=0){
		return x;
	}
	return x_of_y(p_0,Node(p_1.x+l*((x_0<p_1.x)?-1:1),p_1.y),h);
}
bool check(const double &s){
	double x_l=e_2,x_r=e_2;
	a[0]=Node(x_of_y(Node(e_1,0),Node(e_2,h),1),1);
	for(int i=1;i<=n;i++){
		p_0=a[i-1],p_1=a[i];
		l=s*(t[i]-t[i-1]);
		if(!cmp(p_1.y-p_0.y)&&cmp(std::abs(p_1.x-p_0.x)-l)>0){
			return 0;
		}
		double n_l=std::max(0.0,x_of_y(p_1,Node(w,0),h)),n_r=std::min(w,x_of_y(p_1,Node(0,0),h));
		double x_l_1=fix(x_l);
		if(cmp(x_l_1-x_l)<0){
			return 0;
		}
		x_l=x_l_1;
		double x_r_1=fix(x_r);
		if(cmp(x_r_1-x_r)>0){
			return 0;
		}
		x_r=x_r_1;
		if(cmp(x_l-x_r)>0){
			return 0;
		}
		x_l=std::max(n_l,std::max(x_l-l,x_of_y(Node(x_of_y(p_0,Node(x_l,h),0)+l,0),p_1,h)));
		x_r=std::min(n_r,std::min(x_r+l,x_of_y(Node(x_of_y(p_0,Node(x_r,h),0)-l,0),p_1,h)));
		if(cmp(x_l-x_r)>0){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d%lf%lf%lf%lf",&n,&w,&h,&e_1,&e_2);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&t[i],&a[i].x,&a[i].y);
	}
	if(!check(w+1)){
		puts("-1");
		return 0;
	}
	double l=0,r=w+1;
	while(r-l>1e-6){
		double mid=(l+r)/2;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	printf("%.6lf\n",r);
	return 0;
}