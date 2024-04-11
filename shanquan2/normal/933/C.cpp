#include<bits/stdc++.h>
using namespace std;

struct fe{
	int x,y,r;
	bool operator <(const fe &o)const{
		return x<o.x||x==o.x&&y<o.y||x==o.x&&y==o.y&&r<o.r;
	}
	bool operator ==(const fe &o)const{
		return x==o.x&&y==o.y&&r==o.r;
	}
}a[5];
int n,b[5][5];
int ins(fe a,fe b){
	int u=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y),v=(a.r-b.r)*(a.r-b.r),w=(a.r+b.r)*(a.r+b.r);
	if(u==v||u==w)return 1;
	if(v<u&&u<w)return 2;
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
	sort(a,a+n);
	n=unique(a,a+n)-a;
	if(n==1){
		printf("2\n");
		return 0;
	}
	if(n==2){
		int f=ins(a[0],a[1]);
		if(f==2)printf("4\n");
		else printf("3\n");
		return 0;
	}
	int v=0;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j){
		b[i][j]=ins(a[i],a[j]);
	}
	int f=-1;
	for(int i=0;i<n;i++){
		bool g=1;
		for(int j=0;j<n;j++)if(i!=j&&b[i][j]){g=0;break;}
		if(g){f=i;break;}
	}
	if(f!=-1){
		int u=0,v=1;
		if(f==0)u=2;
		if(f==1)v=2;
		if(b[u][v]==2)printf("5\n");
		else printf("4\n");
		return 0;
	}
	double a1=2*(a[0].x-a[1].x),b1=2*(a[0].y-a[1].y),c1=a[1].r*a[1].r-a[0].r*a[0].r+a[0].x*a[0].x-a[1].x*a[1].x+a[0].y*a[0].y-a[1].y*a[1].y;
	double a2=2*(a[0].x-a[2].x),b2=2*(a[0].y-a[2].y),c2=a[2].r*a[2].r-a[0].r*a[0].r+a[0].x*a[0].x-a[2].x*a[2].x+a[0].y*a[0].y-a[2].y*a[2].y;
	int ans=0;
	if(fabs(a1*b2-a2*b1)<1e-6){
		if(fabs(a1*c2-a2*c1)<1e-6&&fabs(b1*c2-b2*c1)<1e-6){
			double d=fabs(a1*a[0].x+b1*a[0].y-c1)/sqrt(a1*a1+b1*b1);
			if(fabs(d-a[0].r)<1e-6)ans--;
			else if(d<a[0].r)ans-=2;
		}
	}else{
		double x=(c1*b2-c2*b1)/(a1*b2-a2*b1),y=(a1*c2-a2*c1)/(a1*b2-a2*b1);
		if(fabs((x-a[0].x)*(x-a[0].x)+(y-a[0].y)*(y-a[0].y)-a[0].r*a[0].r)<1e-6)ans--;
	}
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)ans+=b[i][j];
	printf("%d\n",ans+2);
	return 0;
}