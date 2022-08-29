#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=1100;
const db pi=acos(-1.0);
//const db eps=1e-13;
struct poi{
	db x,y;
	inline poi(db a=0,db b=0){x=a;y=b;}
}a[N];int n,w,h;
inline poi operator +(const poi &a,const poi &b){return poi(a.x+b.x,a.y+b.y);}
inline poi operator -(const poi &a,const poi &b){return poi(a.x-b.x,a.y-b.y);}
inline poi operator /(const poi &a,const db &b){return poi(a.x/b,a.y/b);}
inline poi operator *(const poi &a,const db &b){return poi(a.x*b,a.y*b);}
inline db operator *(const poi &a,const poi &b){return a.x*b.y-a.y*b.x;}
inline db sqr(const db &x){return x*x;}
inline db dis(poi a,poi b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
#define pdi pair<double,int>
vector<pdi>seg;
inline void work(db L,db R,int gt){
	if(L<-pi){
		seg.pb(pdi(L+2.*pi,gt));seg.pb(pdi(pi,-gt));
		seg.pb(pdi(-pi,gt));seg.pb(pdi(R,-gt));
	}
	else if(R>pi){
		seg.pb(pdi(L,gt));seg.pb(pdi(pi,-gt));
		seg.pb(pdi(-pi,gt));seg.pb(pdi(R-2.*pi,-gt));
	}
	else{
		seg.pb(pdi(L,gt));seg.pb(pdi(R,-gt));
	}
}
inline bool ck(int me,db r){
	seg.clear();
	rep(i,1,n)if(dis(a[me],a[i])>0&&dis(a[me],a[i])<2.*r){
		db D=dis(a[me],a[i])/2.;
		db delta=acos(D/r);
		db middle=atan2(a[i].y-a[me].y,a[i].x-a[me].x);
		db L=middle-delta;
		db R=middle+delta;
		work(L,R,1);
	}
	if(a[me].y-r<0){
		db d=acos(a[me].y/r);
		work(-pi/2-d,-pi/2+d,2);
	}
	if(a[me].y+r>h){
		db d=acos((h-a[me].y)/r);
		work(pi/2-d,pi/2+d,2);
	}
	if(a[me].x-r<0){
		db d=acos(a[me].x/r);
		work(-pi-d,-pi+d,2);
	}
	if(a[me].x+r>w){
		db d=acos((w-a[me].x)/r);
		work(-d,d,2);
	}
	int zt=0;
	seg.pb(pdi(pi,0));
	sort(seg.begin(),seg.end());
	db bef=-pi;
	rep(i,0,seg.size()-1){
		if(seg[i].fi>bef&&zt<=1)return 1;
		bef=seg[i].fi;zt+=seg[i].se;
	}
	return 0;
}
inline db kuo(int me,db l,db r){
	while(l+1e-9<=r){
		db mid=(l+r)/2;
		if(ck(me,mid))l=mid;
		else r=mid;
	}
	return (l+r)/2;
}
int main(){
	scanf("%d%d%d",&w,&h,&n);
	rep(i,1,n)scanf("%lf%lf",&a[i].x,&a[i].y);
	random_shuffle(a+1,a+n+1);
	db ans=0;
	rep(i,1,n)if(ck(i,ans)){
		ans=kuo(i,ans,2e6);
	}
	printf("%.15lf\n",ans);
	return 0;
}