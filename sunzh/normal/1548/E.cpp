#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m,x;
int a[200010],b[200010];
int na[200010],nb[200010];
int que[200010],mx[200010],head,tail;
void init(){
	head=1,tail=0;
	memset(na,0x3f,sizeof(na));memset(nb,0x3f,sizeof(nb));
	// a[n+1]=0x3f3f3f3f,a[n+2]=0;
	for(int i=1;i<=n;++i){
		while(head<=tail&&a[que[tail]]>a[i]){
			na[que[tail]]=min(na[que[tail]],mx[tail]);
			mx[tail-1]=max(mx[tail-1],max(a[que[tail]],mx[tail]));
			--tail;
		}
		que[++tail]=i,mx[tail]=-2e7;
	}
	head=1,tail=0;
	for(int i=n;i>=1;--i){
		while(head<=tail&&a[que[tail]]>=a[i]){
			na[que[tail]]=min(na[que[tail]],mx[tail]);
			mx[tail-1]=max(mx[tail-1],max(a[que[tail]],mx[tail]));
			--tail;
		}
		que[++tail]=i,mx[tail]=-2e7;
	}
	head=1,tail=0;
	for(int i=1;i<=m;++i){
		while(head<=tail&&b[que[tail]]>b[i]){
			nb[que[tail]]=min(nb[que[tail]],mx[tail]);
			mx[tail-1]=max(mx[tail-1],max(b[que[tail]],mx[tail]));
			--tail;
		}
		que[++tail]=i;mx[tail]=-2e7;
	}
	head=1;tail=0;
	for(int i=m;i>=1;--i){
		while(head<=tail&&b[que[tail]]>=b[i]){
			// printf("i:%d,tail:%d,mx:%d\n",i,que[tail],mx[tail]);
			nb[que[tail]]=min(nb[que[tail]],mx[tail]);
			mx[tail-1]=max(mx[tail-1],max(b[que[tail]],mx[tail]));
			--tail;
		}
		que[++tail]=i;mx[tail]=-2e7;
	}
	// printf("%d\n",nb[1]);
}
int id1[200010],id2[200010];
struct BIT{
	int siz;
	int tre[200010];
	void init(int sz){
		siz=sz;
	}
	void update(int x){
		while(x<=siz){
			tre[x]++;x+=x&-x;
		}
	}
	int query(int x){
		x=max(x,0);
		int res=0;
		while(x) res+=tre[x],x-=x&-x;
		return res;
	}
}T[2];
struct nd{
	int id,op;PII val;
}c[4000010];
int main(){
	n=read(),m=read(),x=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i) b[i]=read();
	init();
	for(int i=1;i<=n;++i) if(na[i]>2e7) na[i]=x+1;
	for(int i=1;i<=m;++i){
		// printf("nb[%d]=%d\n",i,nb[i]);
		if(nb[i]>2e7) nb[i]=x+1;
	}
	// for(int i=1;i<=n;++i) printf("na[%d]=%d\n",i,na[i]);
	// for(int i=1;i<=m;++i) printf("nb[%d]=%d\n",i,nb[i]);
	for(int i=1;i<=n;++i) c[i].id=i,c[i].op=0,c[i].val=mp(na[i]-a[i],a[i]);
	for(int i=1;i<=m;++i) c[i+n].id=i,c[i+n].op=1,c[i+n].val=mp(nb[i]-b[i],b[i]);
	sort(c+1,c+n+m+1,[&](nd x,nd y){
		return x.val>y.val;
	});
	T[0].init(2e5);T[1].init(2e5);
	long long ans=0;
	for(int i=1;i<=n+m;++i){
		int l,r;
		if(c[i].op==0) l=x-na[c[i].id],r=x-a[c[i].id];
		else l=x-nb[c[i].id],r=x-b[c[i].id];
		if(l>2e6) break ;
		// printf("id:%d,op:%d\n",c[i].id,c[i].op);
		// printf("l:%d,r:%d\n",l,r);
		if(l<=r){
			ans+=T[c[i].op^1].query(r)-T[c[i].op^1].query(l);
			// printf("%d %d\n",T[c[i].op^1].query(r),T[c[i].op^1].query(l));
			// printf("%d\n",ans);
		}
		// printf("%d\n",c[i].val.se);
		T[c[i].op].update(c[i].val.se);
	}
	printf("%lld\n",ans);
}