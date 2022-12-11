#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

const int N = 4e5+5;
const db pi = acos(-1);
const db eps = 1e-10;

int n;
db R;
struct point{
	db x,y;
	point(const db x_=0,const db y_=0){x=x_;y=y_;}
	
	void read(){
		scanf("%lf%lf",&x,&y);
	}
}a[N],b[N],c[N],d[N];
int m,u,k;

point operator +(point a,point b){return point(a.x+b.x,a.y+b.y);}
point operator -(point a,point b){return point(a.x-b.x,a.y-b.y);}
point rotate90(point a){return point(-a.y,a.x);}
db operator *(point a,point b){return a.x*b.y-a.y*b.x;}
db operator &(point a,point b){return a.x*b.x+a.y*b.y;}
db cross(point a,point b,point c){return (b-a)*(c-a);}
db length(point a){return sqrt(a&a);}
db distance(point a,point b){return length(a-b);}

bool cmp1(point a,point b){
	if (fabs(a.x-b.x)<eps)return a.y<b.y;
	return a.x<b.x;
}

point O;

bool cmp2(point a,point b){
	db v=(a-O)*(b-O);
	if (fabs(v)>eps)return v>0;
	return (a-O)*(a-O)<(b-O)*(b-O);
}

void convexhull(point *a,point *b,int &n,int &m){
	sort(a+1,a+1+n,cmp1);
	O=a[1];
	sort(a+2,a+1+n,cmp2);
	m=0;
	fo(i,1,n){
		while(m>1&&(b[m]-b[m-1])*(a[i]-b[m-1])<eps)m--;
		b[++m]=a[i];
	}
}

db angle(point a,point O,point b){return acos(((a-O)&(b-O))/length(a-O)/length(b-O));}

bool bz[N];

bool check(point a,point O,point b){
	db alpha=angle(a,O,b);
	db beta=asin(length(a-b)/2/R);
	return alpha+beta>pi-eps;
}

db calc(point a,point b){
	db alpha=asin(length(a-b)/2/R);
	db ret=alpha*R*R;
	db y=sqrt(R*R-((a-b)&(a-b))/4);
	return ret-y*length(a-b)/2;
}

int main(){
//	freopen("data.in","r",stdin);
	scanf("%d%lf",&n,&R);
	fo(i,1,n)a[i].read();
	if (n==1)return printf("0\n"),0;
	convexhull(a,b,n,m);
	int he=1,ta=2;
	c[1]=b[1],c[2]=b[2];
	fo(i,3,m)
	if (!check(c[he],b[i],c[ta])){
		for(;he<ta&&check(c[he+1],c[he],b[i]);he++);
		for(;he<ta&&check(c[ta-1],c[ta],b[i]);ta--);
		c[++ta]=b[i];
	}
	c[ta+1]=c[he];
	db ans=0;
	fo(i,he,ta)ans=ans+c[i]*c[i+1];
	ans=ans/2;
	if (ans<0)ans=-ans;
	fo(i,he,ta)ans=ans+calc(c[i],c[i+1]);
	printf("%.9lf\n",ans);
	return 0;
}