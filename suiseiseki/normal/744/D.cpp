#include <ctime>
#include <cmath>
#include <cstdio>
#include <random>
#include <iostream>
#include <algorithm>
#define double long double
const int Maxn=1000;
const double PI=acos(-1.0);
const double PI_2=2*PI;
const int Inf=(Maxn<<1);
const double eps=1e-8;
int n_r,n_b;
std::mt19937 rnd(time(NULL));
struct Node{
	double x,y;
	Node(double _x=0,double _y=0){
		x=_x,y=_y;
	}
	friend bool operator ==(Node a,Node b){
		return a.x==b.x&&a.y==b.y;
	}
	friend Node operator -(Node a,Node b){
		return Node(a.x-b.x,a.y-b.y);
	}
	double find_sqr(){
		return x*x+y*y;
	}
	double find_dis(){
		return sqrt(x*x+y*y);
	}
}a_r[Maxn+5],a_b[Maxn+5];
bool find_inter(Node a,Node b,double r,double &ans_l,double &ans_r){
	if(a==b){
		return 0;
	}
	Node dis=b-a;
	double d=dis.find_dis();
	if(d>2*r){
		return 0;
	}
	double t=acos(dis.find_sqr()/(2*d*r));
	double m=atan2(dis.y,dis.x);
	ans_l=m-t,ans_r=m+t;
	while(ans_l<0){
		ans_l+=PI_2;
	}
	while(ans_l>PI_2){
		ans_l-=PI_2;
	}
	while(ans_r<0){
		ans_r+=PI_2;
	}
	while(ans_r>PI_2){
		ans_r-=PI_2;
	}
	return 1;
}
struct Segment{
	double pos;
	int val;
	friend bool operator <(Segment a,Segment b){
		if(a.pos==b.pos){
			return a.val<b.val;
		}
		return a.pos<b.pos;
	}
	Segment(double _pos=0,int _val=0){
		pos=_pos,val=_val;
	}
}seg[Maxn<<3|5];
bool check(Node a,double r,bool cov_red=0){
	int seg_len=0;
	if(cov_red){
		seg[++seg_len]=Segment(0,1);
	}
	double ans_l,ans_r;
	for(int i=1;i<=n_r;i++){
		if(find_inter(a,a_r[i],r,ans_l,ans_r)){
			if(ans_l<=ans_r){
				seg[++seg_len]=Segment(ans_l,1);
				seg[++seg_len]=Segment(ans_r,-1);
			}
			else{
				seg[++seg_len]=Segment(0,1);
				seg[++seg_len]=Segment(ans_r,-1);
				seg[++seg_len]=Segment(ans_l,1);
			}
		}
	}
	for(int i=1;i<=n_b;i++){
		if(find_inter(a,a_b[i],r,ans_l,ans_r)){
			if(ans_l<=ans_r){
				seg[++seg_len]=Segment(ans_l,-Inf);
				seg[++seg_len]=Segment(ans_r,Inf);
			}
			else{
				seg[++seg_len]=Segment(0,-Inf);
				seg[++seg_len]=Segment(ans_r,Inf);
				seg[++seg_len]=Segment(ans_l,-Inf);
			}
		}
	}
	std::sort(seg+1,seg+1+seg_len);
	int sum=0;
	for(int i=1;i<=seg_len;i++){
		sum+=seg[i].val;
		if(sum>0){
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n_r,&n_b);
	for(int i=1;i<=n_r;i++){
		scanf("%Lf%Lf",&a_r[i].x,&a_r[i].y);
	}
	for(int i=1;i<=n_b;i++){
		scanf("%Lf%Lf",&a_b[i].x,&a_b[i].y);
	}
	std::shuffle(a_r+1,a_r+1+n_r,rnd);
	std::shuffle(a_b+1,a_b+1+n_b,rnd);
	double ans=1;
	for(int i=1;i<=n_r;i++){
		if(check(a_r[i],ans,1)){
			double left=ans,right=1e9;
			while(right-left>eps){
				double mid=(left+right)/2;
				if(check(a_r[i],mid,1)){
					left=mid;
				}
				else{
					right=mid;
				}
			}
			ans=left;
		}
	}
	for(int i=1;i<=n_b;i++){
		if(check(a_b[i],ans)){
			double left=ans,right=1e9;
			while(right-left>eps){
				double mid=(left+right)/2;
				if(check(a_b[i],mid)){
					left=mid;
				}
				else{
					right=mid;
				}
			}
			ans=left;
		}
	}
	if(ans>1e9-0.3){
		puts("-1");
	}
	else{
		printf("%.9Lf\n",ans);
	}
	return 0;
}