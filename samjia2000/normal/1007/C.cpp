#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

LL get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		LL s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	LL s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

struct point{
	LL x,y;
	point(const LL x_=0,const LL y_=0){x=x_;y=y_;}
};
point operator +(point a,point b){return point(a.x+b.x,a.y+b.y);}

point goal,pt[10];
int c12[10],c13[10],c23[10];
int m;
int cnt;

LL absll(LL x){return x<0?-x:x;}

int query(point a){
	cout<<a.x<<" "<<a.y<<endl;
	fflush(stdout);
	return get();
}

int main(){
	LL n=get();
	point A=point(1,1),B=point(n+1,n+1),C=point(n,n);
	while(A.x<=C.x&&A.y<=C.y){
		point Mid=point(B.x-A.x,B.y-A.y);
		LL lx=C.x-A.x+1,ly=C.y-A.y+1;
		db S=db(1)*lx*ly-db(1)*(C.y-B.y+1)*(C.x-B.x+1);
		db l=0,r=S;
		while(l+1<r&&(r-l)/r>1e-6){
			db mid=(l+r)/2;
			LL dx=mid/ly,dy=mid/lx;
			db tmp=S-(db(1)*dx*ly+db(1)*dy*lx-db(1)*dx*dy);
			if (tmp>=mid)l=mid;
			else r=mid;
		}
		LL dx=l/ly,dy=l/lx;
		Mid=A+point(dx,dy);
		if (Mid.x>=B.x)Mid.x=B.x-1;
		if (Mid.y>=B.y)Mid.y=B.y-1;
		int ty=query(Mid);
		if (ty==0){
			return 0;
		}
		if (ty==1){
			A.x=Mid.x+1;
			if (B.x<=A.x){
				C.y=B.y-1;
				B.x=C.x+1,B.y=C.y+1;
			}
		}
		if (ty==2){
			A.y=Mid.y+1;
			if (B.y<=A.y){
				C.x=B.x-1;
				B.x=C.x+1,B.y=C.y+1;
			}
		}
		if (ty==3){
			B=Mid;
			if (B.x==A.x){
				C.y=B.y-1;
				B.x=C.x+1,B.y=C.y+1;
			}
			else
				if (B.y==A.y){
					C.x=B.x-1;
					B.x=C.x+1,B.y=C.y+1;
				}
		}
	}
	return 0;
}