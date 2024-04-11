#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long LL;
LL jsb;
LL mult(LL x,LL y){
	LL res=0;
	x%=jsb;
	bool f=0;
	if(y<0)f=1,y*=-1;
	while(y){
		res=(res+x*(y&255))%jsb;
		x=(x<<8)%jsb;
		y>>=8;
	}
	if(f)res*=-1;
	return res;
}
LL n2he(LL x){
	if(!x)return 0;
	LL x1,x2,x3;
	x1=x;
	x2=x+1;
	x3=(2ll*x+1)%jsb;
	if(x1%2ll==0)x1/=2ll;
	else x2/=2ll;
	
	if(x1%3ll==0)x1/=3ll;else if(x2%3ll==0)x2/=3ll;else x3/=3ll;
	return mult(x1,mult(x2,x3));
}
LL fat1(LL p,LL X){
	LL x1,x2;
	x1=p+1ll;x2=p;
	if(x1%2==0)x1/=2ll;else x2/=2ll;
	
	LL r1=mult(mult(x1,x2),X-p);
	LL r2=(n2he(X-1ll)-n2he(p-1ll))%jsb;
	
	r2=mult(r2,p);
	return (r1+r2)%jsb;
}
LL fat2(LL p,LL X){
	LL x1,x2;
	x1=p-1ll;x2=p;
	if(x1%2==0)x1/=2ll;else x2/=2ll;
	
	LL r1=mult(mult(x1,x2),X-p);
	LL r2=(n2he(X)-n2he(p))%jsb;
	
	r2=mult(r2,p);
	return (r2-r1)%jsb;
}
LL fat(LL x,LL y){
	if(!x||!y)return 0;LL res=0;
	LL mc=mult(min(x,y),min(x,y));
	LL x1=mc+1ll;LL x2=mc;
	if(x1%2==0)x1/=2ll;else x2/=2ll;
	res=mult(x1,x2);
	if(x==y)return res;
	LL bc=min(x,y);
	if(y>=x)res=(res+fat1(bc,y));
	else res=(res+fat2(bc,x));
	return (res%jsb+jsb)%jsb;
}
void Out(LL x)
{
	x%=jsb;
	x=(x+jsb)%jsb;
	x=(x+(LL)1e10)%(LL)1e10;
	printf("...");
	#define Pu printf("0")
	//if(x<1e10)Pu;
	if(x<1e9)Pu;
	if(x<1e8)Pu;
	if(x<1e7)Pu;
	if(x<1e6)Pu;
	if(x<1e5)Pu;
	if(x<1e4)Pu;
	if(x<1e3)Pu;
	if(x<1e2)Pu;
	if(x<1e1)Pu;
	printf("%I64d\n",x);
}
void Work(LL x1,LL y1,LL x2,LL y2){
	jsb=(LL)(1e10);
	jsb*=7212ll;
	LL res=(fat(x2,y2)-fat(x1-1,y2)-fat(x2,y1-1)+fat(x1-1,y1-1))%jsb;
	res=(res+jsb)%jsb;
	if(res>=LL(1e10)){
		Out(res);
		return;
	}
	
	jsb=(LL)(1e10);
	jsb*=2432ll;
	res=(fat(x2,y2)-fat(x1-1,y2)-fat(x2,y1-1)+fat(x1-1,y1-1))%jsb;
	res=(res+jsb)%jsb;
	if(res>=LL(1e10)){
		Out(res);
		return;
	}
	
	jsb=(LL)(1e10);
	jsb*=1792ll;
	res=(fat(x2,y2)-fat(x1-1,y2)-fat(x2,y1-1)+fat(x1-1,y1-1))%jsb;
	res=(res+jsb)%jsb;
	if(res>=LL(1e10)){
		Out(res);
		return;
	}
	jsb=(1e10);
	printf("%I64d\n",(res%jsb+jsb)%jsb);
}
int main()
{
	int t;scanf("%d",&t);
	while(t--){
		LL x1,x2,y1,y2;scanf("%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2);
		Work(x1,y1,x2,y2);
	}
	return 0;
}