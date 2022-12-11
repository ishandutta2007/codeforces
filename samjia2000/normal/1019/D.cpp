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

const int N = 2005;
const int L = 4e6+5;

int n;
LL S;
struct point{
	LL x,y;
	point(const LL x_=0,const LL y_=0){x=x_;y=y_;}
}a[N];
struct Direction{
	int ty;
	LL x,y;
	int kx,ky;
	Direction(const int ty_=0,const LL x_=0,const LL y_=0){ty=ty_;x=x_;y=y_;}
}direc[L];
point operator -(point a,point b){return point(a.x-b.x,a.y-b.y);}
int k;
point O;

LL cross(point a,point b,point c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}

LL cross(point a,point b){return a.x*b.y-a.y*b.x;}

LL cross(Direction a,Direction b){return a.x*b.y-a.y*b.x;}

int gettype(point a){
	if (a.y==0)return a.x>0?1:2;
	return a.y>0?1:2;
}

bool cmp(Direction a,Direction b){
	return a.ty!=b.ty?a.ty<b.ty:cross(a,b)>0;
}

int num[N];
int rk[N];

bool cmp1(int x,int y){return a[x].y<a[y].y;}

void putpoint(point a){
	cout<<a.x<<" "<<a.y<<endl;
}

int main(){
	O=point(0,0);
	n=get();S=get();
	fo(i,1,n){
		a[i].x=get();a[i].y=get();
	}
	fo(i,1,n)
		fo(j,1,n)
		if (i!=j){
			point tmp=a[j]-a[i];
			direc[++k]=Direction(gettype(tmp),tmp.x,tmp.y);
			direc[k].kx=i,direc[k].ky=j;
			if (direc[k].ty==2)k--;
		}
	sort(direc+1,direc+1+k,cmp);
	fo(i,1,n)num[i]=i;
	sort(num+1,num+1+n,cmp1);
	fo(i,1,n)rk[num[i]]=i;
	S=S*2;
	fo(i,1,k){
		int kx=direc[i].kx,ky=direc[i].ky;
		if (rk[kx]+1==rk[ky]){
			swap(num[rk[kx]],num[rk[ky]]);
			rk[kx]++,rk[ky]--;
		}
		int l=1,r=n,ret=0;
		while(l<=r){
			int mid=(l+r)/2;
			if (cross(a[kx],a[ky],a[num[mid]])>S)r=mid-1;
			else ret=mid,l=mid+1;
		}
		if (ret&&cross(a[kx],a[ky],a[num[ret]])==S){
			printf("Yes\n");
			putpoint(a[num[ret]]);
			putpoint(a[kx]);
			putpoint(a[ky]);
			return 0;
		}
		l=1,r=n,ret=0;
		while(l<=r){
			int mid=(l+r)/2;
			if (cross(a[kx],a[ky],a[num[mid]])>-S)r=mid-1;
			else ret=mid,l=mid+1;
		}
		if (ret&&cross(a[kx],a[ky],a[num[ret]])==-S){
			printf("Yes\n");
			putpoint(a[num[ret]]);
			putpoint(a[kx]);
			putpoint(a[ky]);
			return 0;
		}
	}
	printf("No\n");
	return 0;
}