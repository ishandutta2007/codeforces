#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define max_N 2005

struct poi{
	int x,y;
	poi(int x=0,int y=0):x(x),y(y){}
	friend poi operator-(const poi&a,const poi&b){
		return poi(a.x-b.x,a.y-b.y);
	}
}p[max_N],p1[max_N];

int n,cur,ans;

bool cmp(const poi&a,const poi&b){
	return a.x!=b.x?a.x<b.x:a.y<b.y;
}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

bool check(const poi&a,const poi&b){
	return a.x==b.x&&a.y==b.y;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+1+n,cmp);
	for(cur=1;cur<=n-2;++cur){
		ans+=(n-cur)*(n-cur-1)/2;
		for(int i=1;i<=n-cur;++i){
			p1[i]=p[i+cur]-p[cur];
			int g=gcd(abs(p1[i].x),abs(p1[i].y));
			p1[i].x/=g,p1[i].y/=g;
			if(p1[i].y<0){
				p1[i].x=-p1[i].x,
				p1[i].y=-p1[i].y;
			}
		}
		sort(p1+1,p1+1+n-cur,cmp);
		int cnt=0;
		for(int i=1;i<=n-cur;++i){
			if(i!=1&&!check(p1[i],p1[i-1])){
				if(cnt>=2)ans-=cnt*(cnt-1)/2;
				cnt=0;
			}
			++cnt;
		}
		if(cnt>=2)ans-=cnt*(cnt-1)/2;
	}
	printf("%d\n",ans);
	return 0;	
}