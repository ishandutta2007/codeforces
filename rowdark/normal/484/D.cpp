#include<stdio.h>
#include<algorithm>
#include<stack>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn=1048576;
struct rec{
	int l,r,c;
	rec(){}
	rec(int l,int r,int c):l(l),r(r),c(c){}
	void Union(const rec &a){
		l=a.l;
	}
};
struct node{
	LL add,maxv;
	LL getmax(){return maxv+add;}
	void renew(LL x,LL y){maxv=max(x,y);}
	void pushdown(node &x,node &y){
		x.add+=add,y.add+=add;
		add=0;
	}
}a[3000000];

void add(int l,int r,int ll,int rr,int now,LL v){
	if(l==ll&&r==rr){
		a[now].add+=v;
		return;
	}
	if(a[now].add){
		a[now].pushdown(a[now*2],a[now*2+1]);
	}
	int mid=(ll+rr)>>1;
	if(r<=mid) add(l,r,ll,mid,now*2,v);
	else if(l>mid) add(l,r,mid+1,rr,now*2+1,v);
	else add(l,mid,ll,mid,now*2,v),add(mid+1,r,mid+1,rr,now*2+1,v);
	a[now].renew(a[now*2].getmax(),a[now*2+1].getmax());
}

LL dp[3000000];

stack<rec> mmin,mmax;

int b[1001000];
int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",b+i);
	}
	for(int i=1;i<=n;++i){
		{
			rec now(i-1,i-1,b[i]);
			while(!mmin.empty()&&mmin.top().c>=now.c){
				add(mmin.top().l,mmin.top().r,0,maxn-1,1,mmin.top().c);
				now.Union(mmin.top());
				mmin.pop();
			}
			add(now.l,now.r,0,maxn-1,1,-now.c);
			mmin.push(now);
		}
		{
			rec now(i-1,i-1,b[i]);
			while(!mmax.empty()&&mmax.top().c<=now.c){
				add(mmax.top().l,mmax.top().r,0,maxn-1,1,-mmax.top().c);
				now.Union(mmax.top());
				mmax.pop();
			}
			add(now.l,now.r,0,maxn-1,1,now.c);
			mmax.push(now);
		}
		dp[i]=a[1].getmax();
		add(i,i,0,maxn-1,1,dp[i]);
	}
	cout<<dp[n]<<endl;
	return 0;
}