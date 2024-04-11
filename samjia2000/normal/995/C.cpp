#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 100005;

struct point{
	db x,y;
	point(const db x_=0,const db y_=0){x=x_;y=y_;}
}a[N];
int n;
int c[N];
point operator +(point a,point b){return point(a.x+b.x,a.y+b.y);}
point operator -(point a,point b){return point(a.x-b.x,a.y-b.y);}
int num[N];

int main(){
	n=get();
	fo(i,1,n)scanf("%lf%lf",&a[i].x,&a[i].y);
	fo(i,1,n)num[i]=i;
	srand(20010419);
	db dis= 1e9;
	while(dis>1.5e6){
		random_shuffle(num+1,num+1+n);
		fo(i,1,n)c[i]=1;
		point now=point(0,0);
		fo(x,1,n){
			int i=num[x];
			point u=now+a[i];
			point v=now-a[i];
			if (u.x*u.x+u.y*u.y<v.x*v.x+v.y*v.y){
				c[i]=1;
				now=u;
			}
			else{
				c[i]=-1;
				now=v;
			}
		}
		dis=sqrt(now.x*now.x+now.y*now.y);
	}
	fo(i,1,n)printf("%d ",c[i]);putchar('\n');
	return 0;
}