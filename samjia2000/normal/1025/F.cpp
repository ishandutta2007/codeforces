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

const int N = 2005;

int n;
struct point{
	int x,y;
	point(const int x_=0,const int y_=0){x=x_;y=y_;}
}a[N],b[N*2];
point operator +(point a,point b){return point(a.x+b.x,a.y+b.y);}
point operator -(point a,point b){return point(a.x-b.x,a.y-b.y);}
LL cross(point a,point b,point c){return 1ll*(b.x-a.x)*(c.y-a.y)-1ll*(c.x-a.x)*(b.y-a.y);}

int gettype(point a){
	if (a.y==0)return a.x>0?1:2;
	return a.y>0?1:2;
}

bool cmp(point a,point b){
	int tx=gettype(a),ty=gettype(b);
	if (tx!=ty)return tx<ty;
	return cross(point(0,0),a,b)>0;
}

LL calc(LL n){return n*(n-1)/2;}

int main(){
	n=get();
	fo(i,1,n){a[i].x=get();a[i].y=get();}
	LL ans=0;
	fo(i,1,n){
		int k=0;
		fo(j,1,n)
		if (i!=j)b[++k]=a[j]-a[i];
		sort(b+1,b+1+k,cmp);
		fo(i,1,k)b[k+i]=b[i];
		int w=1;
		fo(x,1,k){
			w=max(w,x);
			while(w-x+2<=k&&cross(point(0,0),b[x],b[w+1])>0)w++;
			int l=w-x,r=n-1-l-1;
			ans=ans+calc(l)*calc(r);
		}
	}
	ans=ans/2;
	cout<<ans<<endl;
	return 0;
}