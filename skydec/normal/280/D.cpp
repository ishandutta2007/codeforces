#include<cstdio>
#include<cstring>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
#define MAXN 110000
using namespace std;
inline void s(int &x,int &y){int tmp=x;x=y;y=tmp;}
inline int Min(const int &x,const int &y){if(x<y)return x;return y;}
inline int Max(const int &x,const int &y){if(x>y)return x;return y;}
#define set Set
struct info{
	int leftmin,rightmin;
	int leftmax,rightmax;
	int allmax,allmin;
	int l,r;int ml,mr;
	int lmi,lma,rmi,rma;
	int sum;
	inline void set(int x,int num){
		l=r=ml=mr=lmi=lma=rmi=rma=num;
		leftmin=rightmin=leftmax=rightmax=x;
		allmax=allmin=x;
		sum=x;
		}
	inline void fan(){
		s(leftmin,leftmax);leftmin*=-1;leftmax*=-1;
		s(rightmin,rightmax);rightmax*=-1;rightmin*=-1;
		s(allmax,allmin);allmax*=-1;allmin*=-1;
		s(l,ml);s(r,mr);sum*=-1;
		s(lmi,lma);
		s(rmi,rma);
		}
}a[MAXN*4];int b[MAXN];
inline info operator +(const info &x,const info &y){
	info res;
	res.leftmin=Min(x.leftmin,x.sum+y.leftmin);if(x.leftmin<x.sum+y.leftmin)res.lmi=x.lmi;else res.lmi=y.lmi;
	res.leftmax=Max(x.leftmax,x.sum+y.leftmax);if(x.leftmax>x.sum+y.leftmax)res.lma=x.lma;else res.lma=y.lma;
	res.rightmin=Min(y.rightmin,y.sum+x.rightmin);if(y.rightmin<y.sum+x.rightmin)res.rmi=y.rmi;else res.rmi=x.rmi;
	res.rightmax=Max(y.rightmax,y.sum+x.rightmax);if(y.rightmax>y.sum+x.rightmax)res.rma=y.rma;else res.rma=x.rma;
	int a1=x.rightmax+y.leftmax;
	int a2=x.allmax;int a3=y.allmax;
	if(a1>=a2&&a1>=a3){
		res.allmax=a1;
		res.l=x.rma;
		res.r=y.lma;
		}
	else if(a2>=a1&&a2>=a3){
		res.allmax=x.allmax;
		res.l=x.l;res.r=x.r;
		}
	else
	{
		res.allmax=y.allmax;
		res.l=y.l;res.r=y.r;
		}
	a1=x.rightmin+y.leftmin;
	a2=x.allmin;a3=y.allmin;
	if(a1<=a2&&a1<=a3){
		res.allmin=a1;
		res.ml=x.rmi;
		res.mr=y.lmi;
		}
	else if(a2<=a1&&a2<=a3){
		res.allmin=x.allmin;
		res.ml=x.ml;
		res.mr=x.mr;
		}
	else
	{
		res.allmin=y.allmin;
		res.ml=y.ml;
		res.mr=y.mr;
		}
	res.sum=x.sum+y.sum;
	return res;
}
bool rev[MAXN*4];
inline void down(int me){
	if(!rev[me])return;
	rev[me*2]^=1;
	rev[me*2+1]^=1;
	a[me*2].fan();
	a[me*2+1].fan();
	rev[me]=0;
}
void change(int now,int l,int r,int x,int v){
	if(l^r)down(now);
	if(l==r){
		a[now].set(v,l);
		return;
		}
	int mid=(l+r)>>1;
	if(x<=mid)change(now*2,l,mid,x,v);
	else change(now*2+1,mid+1,r,x,v);
	a[now]=a[now*2]+a[now*2+1];
}
void build(int now,int l,int r){
	if(l==r){
		a[now].set(b[l],l);
		return;
		}
	int mid=(l+r)>>1;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	a[now]=a[now*2]+a[now*2+1];
}
void qfan(int me,int l,int r,int x,int y){
	if(l^r)down(me);
	if(x<=l&&r<=y){
		rev[me]^=1;
		a[me].fan();
		return;
		}
	int mid=(l+r)>>1;
	if(x<=mid)qfan(me*2,l,mid,x,y);
	if(y>mid)qfan(me*2+1,mid+1,r,x,y);
	a[me]=a[me*2]+a[me*2+1];
}
info ask(int me,int l,int r,int x,int y){
	if(l^r)down(me);
	if(x<=l&&r<=y)return a[me];
	info res;bool flag=false;
	int mid=(l+r)>>1;
	if(x<=mid){
		res=ask(me*2,l,mid,x,y);
		flag=1;
		}
	if(y>mid){
		if(!flag)res=ask(me*2+1,mid+1,r,x,y);
		else res=res+ask(me*2+1,mid+1,r,x,y);
		}
	return res;
}
int n,m;pii q[MAXN];int top=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	build(1,1,n);
	scanf("%d",&m);
	while(m--){
		int opt;scanf("%d",&opt);
		if(!opt){
			int x,val;scanf("%d%d",&x,&val);
			change(1,1,n,x,val);
			}
		else
		{
			int l,r,k;scanf("%d%d%d",&l,&r,&k);
			int top=0;int res=0;
			for(int i=1;i<=k;i++){
				info u=ask(1,1,n,l,r);
				if(u.allmax<=0)break;
				res+=u.allmax;
				qfan(1,1,n,u.l,u.r);
				q[++top]=(pii){u.l,u.r};
				//printf("_%d %d %d\n",u.ml,u.mr,u.allmin);
				}
			for(int i=1;i<=top;i++)
			qfan(1,1,n,q[i].fi,q[i].se);
			printf("%d\n",res);
			}
			}
	return 0;
}