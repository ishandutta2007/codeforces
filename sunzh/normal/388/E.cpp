#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define double long double
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
struct node{
	double x,y,vx,vy;
}a[2010];
double tim[2010];
struct lin{
	double x,y;
}b[2010];
double operator *(lin x,lin y){
	return x.x*y.y-x.y*y.x;
}
const double eps=1e-12;
int ans=1;
bool equ(double x,double y){
	return fabs(x-y)<=eps;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		double t1=read(),x1=read(),y1=read(),t2=read(),x2=read(),y2=read();
		a[i].vx=(x2-x1)/(t2-t1),a[i].vy=(y2-y1)/(t2-t1);
		a[i].x=x1-t1*a[i].vx,a[i].y=y1-t1*a[i].vy;
	}
	for(int i=1;i<=n;++i){
		int tot=0;
		for(int j=1;j<=n;++j){
			if(i!=j){
				node de=node{a[j].x-a[i].x,a[j].y-a[i].y,a[j].vx-a[i].vx,a[j].vy-a[i].vy};
				double Tm=(equ(de.vx,0)?de.y/de.vy:de.x/de.vx);
				if(equ(de.x,de.vx*Tm)&&equ(de.y,de.vy*Tm)){
					tim[++tot]=Tm;
					b[tot]=lin{de.vx,de.vy};
				}
			}
		}
		sort(tim+1,tim+tot+1);
		sort(b+1,b+tot+1,[&](lin x,lin y){
			return equ(atan2(x.y,x.x),atan2(y.y,y.x))?(equ(x.x,y.x)?x.y<y.y:x.x<y.x):atan2(x.y,x.x)<atan2(y.y,y.x);
		});
		for(int j=1;j<=tot;++j){
			int k=j;
			while(k<tot&&equ(tim[k+1],tim[k])) ++k;
			ans=max(ans,k-j+2);j=k;
		}
		// for(int j=1;j<=tot;++j){
		// 	printf("%Lf %Lf\n",b[j].x,b[j].y);
		// }
		// printf("\n\n");
		for(int j=1;j<=tot;++j){
			int k=j,p=0;
			while(k<tot&&equ(b[k]*b[k+1],0.0)){
				++k;p+=(k<=tot&&equ(b[k].x,b[k-1].x)&&equ(b[k].y,b[k-1].y));
			}
			// printf("k:%d,j:%d,p:%d\n",k,j,p);
			ans=max(ans,k-j-p+2);
		}
	}
	printf("%d\n",ans);
}