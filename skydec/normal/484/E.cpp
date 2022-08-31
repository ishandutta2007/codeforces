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
const int N=110000;
inline int Max(const int &a,const int &b){if(a>b)return a;return b;}
struct node{
	int l,r,a,sz;
}mes[N*80];
inline node operator +(const node &a,const node &b){
	node c;c.sz=a.sz+b.sz;
	c.a=Max(a.r+b.l,Max(a.a,b.a));
	if(a.l==a.sz)c.l=a.sz+b.l;else c.l=a.l;
	if(b.r==b.sz)c.r=b.sz+a.r;else c.r=b.r;
	return c;
}
int n;int h[N];int id[N];int tot=0;
inline bool cmp(const int &a,const int &b){return h[a]>h[b];}
int root[N];
int l[N*80],r[N*80];
void build(int &x,int L,int R){
	if(!x)x=++tot;
	if(L==R){
		mes[x].l=mes[x].r=mes[x].a=0;mes[x].sz=1;
		return;
	}
	int mid=(L+R)>>1;
	build(l[x],L,mid);
	build(r[x],mid+1,R);
	mes[x]=mes[l[x]]+mes[r[x]];
}
void modify(int pre,int &me,int L,int R,int x){
	me=++tot;
	if(L==R){
		mes[me].l=mes[me].r=mes[me].a=mes[me].sz=1;
		return;
	}
	int mid=(L+R)>>1;
	if(x<=mid){r[me]=r[pre];modify(l[pre],l[me],L,mid,x);}
	else{l[me]=l[pre];modify(r[pre],r[me],mid+1,R,x);}
	mes[me]=mes[l[me]]+mes[r[me]];
}
node ask(int me,int L,int R,int x,int y){
	if(x<=L&&R<=y)return mes[me];
	int mid=(L+R)>>1;
	if(x<=mid&&y>mid)return ask(l[me],L,mid,x,y)+ask(r[me],mid+1,R,x,y);
	if(x<=mid)return ask(l[me],L,mid,x,y);
	return ask(r[me],mid+1,R,x,y);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){scanf("%d",&h[i]);id[i]=i;}
	sort(id+1,id+1+n,cmp);
	build(root[0],1,n);
	rep(i,1,n)modify(root[i-1],root[i],1,n,id[i]);
	int m;scanf("%d",&m);
	while(m--){
		int L,R,w;scanf("%d%d%d",&L,&R,&w);
		int lp,rp,ans;lp=1;rp=n;ans=0;
		while(lp<rp){
			int mid=(lp+rp)>>1;
			if(ask(root[mid],1,n,L,R).a>=w)rp=mid,ans=mid;
			else lp=mid+1;
		}
		if(ask(root[lp],1,n,L,R).a>=w)ans=lp;
		printf("%d\n",h[id[ans]]);
	}
	return 0;
}