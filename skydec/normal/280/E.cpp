#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
const int MAXN=60005;
int q;
struct line{
	db l,r,k,b;
	inline void move(db u){   // y=kx+b------y=k(x-u)+b=kx-ku+b
		b-=k*u;l+=u;r+=u;
	}
}gt[MAXN];int top=0;db zero[MAXN];
db sqr(db x){return x*x;}
int n,x[MAXN];db ans[MAXN];int a,b;
inline db get(){
	db now=1e20;db res=0;
	rep(i,1,top){
		db zt=(-gt[i].b)/gt[i].k;
		zt=min(max(zt,gt[i].l),gt[i].r);
		db val=gt[i].k*zt+gt[i].b;
		if(fabs(val)<now){
			now=fabs(val);
			res=zt;
		}
	}
	return res;
}
int main(){
	scanf("%d%d%d%d",&n,&q,&a,&b);
	rep(i,1,n)scanf("%d",&x[i]);
	gt[++top]=(line){1,q,2,-2*x[1]};
	ans[1]=get();
	rep(i,2,n){
		int u=top+1;
		db bj=ans[i-1];
		rep(j,1,top)if(gt[j].r>bj){u=j;break;}
		rep(j,1,u-1)gt[j].move(a);
		top+=2;
		per(j,top,u+3)gt[j]=gt[j-2];
		gt[u+2]=gt[u];
		gt[u+1]=(line){bj+a,bj+b,0,0};
		gt[u+2].l=bj;
		gt[u].r=bj;
		rep(j,u+2,top)gt[j].move(b);
		gt[u].move(a);
		rep(j,1,top){
			gt[j].k+=2;
			gt[j].b-=2.*x[i];
		}
		while(gt[top].l>q)top--;
		gt[top].r=min(gt[top].r,1.*q);
		ans[i]=get();
	}
	per(i,n-1,1){
		if(ans[i+1]-ans[i]>b)ans[i]=ans[i+1]-b;
		if(ans[i+1]-ans[i]<a)ans[i]=ans[i+1]-a;
	}
	db res=0;
	rep(i,1,n){
		res+=sqr(ans[i]-x[i]);
		printf("%.8lf ",ans[i]);
	}
	printf("\n");
	printf("%.8lf\n",res);
	return 0;
}