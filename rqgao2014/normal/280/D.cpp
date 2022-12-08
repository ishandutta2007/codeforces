#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<ctime>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debug(x) cout<<#x<<"="<<x<<endl;
using namespace std; 

inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
int n,m,k,a[100005];
struct node{
	int maxl,maxr,minl,minr,maxx,minx;
	int sum,lmx,rmx,mxl,mxr,lmi,rmi,mil,mir;
	bool flag;
}p[800005];
inline node merge(node a,node b){
	node t;t.flag=0;
	t.sum=a.sum+b.sum;
	if(a.maxl>a.sum+b.maxl) t.maxl=a.maxl,t.lmx=a.lmx; else t.maxl=a.sum+b.maxl,t.lmx=b.lmx;
	if(a.minl<a.sum+b.minl) t.minl=a.minl,t.lmi=a.lmi; else t.minl=a.sum+b.minl,t.lmi=b.lmi;
	if(b.maxr>b.sum+a.maxr) t.maxr=b.maxr,t.rmx=b.rmx; else t.maxr=b.sum+a.maxr,t.rmx=a.rmx;
	if(b.minr<b.sum+a.minr) t.minr=b.minr,t.rmi=b.rmi; else t.minr=b.sum+a.minr,t.rmi=a.rmi;
	t.maxx=max(max(a.maxx,b.maxx),a.maxr+b.maxl);
	if(t.maxx==a.maxx) t.mxl=a.mxl,t.mxr=a.mxr;
	else if(t.maxx==b.maxx) t.mxl=b.mxl,t.mxr=b.mxr;
	else if(t.maxx==a.maxr+b.maxl) t.mxl=a.rmx,t.mxr=b.lmx;
	t.minx=min(min(a.minx,b.minx),a.minr+b.minl);
	if(t.minx==a.minx) t.mil=a.mil,t.mir=a.mir;
	else if(t.minx==b.minx) t.mil=b.mil,t.mir=b.mir;
	else if(t.minx==a.minr+b.minl) t.mil=a.rmi,t.mir=b.lmi;
	return t;
}
inline node rev(node x){
	node t;
	if(!x.flag) t.flag=1; else t.flag=0;
	t.sum=-x.sum;
	t.maxl=-x.minl;t.lmx=x.lmi;
	t.minl=-x.maxl;t.lmi=x.lmx;
	t.maxr=-x.minr;t.rmx=x.rmi;
	t.minr=-x.maxr;t.rmi=x.rmx;
	t.maxx=-x.minx;t.mxl=x.mil,t.mxr=x.mir;
	t.minx=-x.maxx;t.mil=x.mxl;t.mir=x.mxr;
	return t;
}
inline void pushdown(int num){
//	printf("push:%d\n",num);
	if(!p[num].flag) return;
//	printf("pushdown: %d to %d %d\n",num,num<<1,num<<1|1);
	
	p[num<<1]=rev(p[num<<1]);p[num<<1|1]=rev(p[num<<1|1]);
	p[num].flag=0;
}
inline void update(int num){
	p[num]=merge(p[num<<1],p[num<<1|1]);
}
inline void change1(int l,int r,int tl,int tr,int num){
	pushdown(num);
	if(l==tl&&r==tr){
		p[num]=rev(p[num]);
		return;
	}
	int mid=(l+r)>>1;
	if(tl<=mid) change1(l,mid,tl,min(tr,mid),num<<1);
	if(tr>mid) change1(mid+1,r,max(mid+1,tl),tr,num<<1|1);
	update(num);
}
inline void newnode(node &a,int b,int c){
	a.flag=0;
	a.maxl=a.maxr=a.maxx=a.minl=a.minr=a.minx=a.sum=b;
	a.mxl=a.mil=a.mxr=a.mir=a.lmx=a.rmx=a.lmi=a.rmi=c;
}
inline void change2(int l,int r,int tl,int x,int num){
	pushdown(num);
	if(l==r){
		newnode(p[num],x,tl);
		return;
	}
	int mid=(l+r)>>1;
	if(tl<=mid) change2(l,mid,tl,x,num<<1); else change2(mid+1,r,tl,x,num<<1|1);
	update(num);
}
inline node query(int l,int r,int tl,int tr,int num){
	pushdown(num);
	if(tl==l&&r==tr) return p[num];
	int mid=(l+r)>>1,vl=0,vr=0;
	node rl,rr;
	if(tl<=mid) vl=1,rl=query(l,mid,tl,min(tr,mid),num<<1);
	if(tr>mid) vr=1,rr=query(mid+1,r,max(mid+1,tl),tr,num<<1|1);
	if(vl&&!vr) return rl;
	if(!vl&&vr) return rr;
	return merge(rl,rr);
}

int main(){
//	freopen("diyiti.in","r",stdin);
//	freopen("diyiti.out","w",stdout);
	memset(p,0,sizeof(p));
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		change2(1,n,i,a[i],1);
//		printf("%d\n",p[1].maxx);
	}
	read(m);
	for(int i=1;i<=m;i++){
		int l,r,opt;
		read(opt);read(l);read(r);
		if(!opt)
			change2(1,n,l,r,1);
		else{
			int k,tot=0,ans=0,ansl[25],ansr[25];
			read(k);
			for(int j=1;j<=k;j++){
				node res=query(1,n,l,r,1);
//				printf("%d %d \n",p[1].maxx,p[1].minx);
				if(res.maxx<=0) continue;
				ans+=res.maxx;ansl[j]=res.mxl;ansr[j]=res.mxr;
//				printf("%d %d ",res.mxl,res.mxr);	printf("%d %d\n",res.maxx,res.minx);
				change1(1,n,ansl[j],ansr[j],1);
//				if(p[1].flag) puts("Yes"); else puts("No");
//			printf("%d\n",query(1,n,1,1,1).minx);
				tot=j;
			}
			printf("%d\n",ans);
			for(int j=1;j<=tot;j++) change1(1,n,ansl[j],ansr[j],1);
//			printf("%d %d\n",p[1].maxx,p[1].minx);
		}
		
	}
	return 0;
}