#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
const int N=1000010;
struct sgt{
	int maxn[8000040];
	int tag[8000040];
	void pushup(int p){
		maxn[p]=max(maxn[p<<1],maxn[p<<1|1]);
	}
	void pushdown(int p){
		if(tag[p]>-1){
			maxn[p<<1]=max(maxn[p<<1],tag[p]);
			maxn[p<<1|1]=max(maxn[p<<1|1],tag[p]);
			tag[p<<1]=max(tag[p<<1],tag[p]);
			tag[p<<1|1]=max(tag[p<<1|1],tag[p]);
			tag[p]=-1;
		}
	}
	void build(int p,int l,int r,int k){
		tag[p]=-1;
		if(l==r){
			maxn[p]=k;
			return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid,k);
		build(p<<1|1,mid+1,r,k);
		pushup(p);
	}
	void update(int p,int l,int r,int L,int R,int k){
		if(l>=L&&r<=R){
			maxn[p]=max(maxn[p],k);tag[p]=max(tag[p],k);return ;
		}
		pushdown(p);
		int mid=l+r>>1;
		if(L<=mid) update(p<<1,l,mid,L,R,k);
		if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
		pushup(p);
	}
	int query(int p,int l,int r,int pos){
		if(l==r) return maxn[p];
		pushdown(p);pushup(p);
		int mid=l+r>>1;
		if(pos<=mid) return query(p<<1,l,mid,pos);
		else return query(p<<1|1,mid+1,r,pos);
	}
}T1,T2;
int n,m;
int a[20010],b[20010];
struct seg{
	int l,r,v;
}s[100010];
int cnt;
int main(){
	memset(T1.maxn,-0x3f,sizeof(T1.maxn));
	memset(T1.tag,-0x3f,sizeof(T1.tag));
	memset(T2.maxn,-0x3f,sizeof(T2.maxn));
//	printf("%d\n",T1.maxn[0]);
	memset(T2.tag,-0x3f,sizeof(T2.tag));
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read(),b[i]=read();
	T1.build(1,0,N,-1);
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		T1.update(1,0,N,0,x,y);
	}
	int pre=-2;
	for(int i=0;i<=N;++i){
		int t=T1.query(1,0,N,i);
		if(t!=pre){
			s[++cnt].l=i;s[cnt].r=i;s[cnt].v=t;pre=t;
		}
		else s[cnt].r=i;
	}
	T2.build(1,0,N,0);
//	for(int i=1;i<=cnt;++i) printf("l:%d,r:%d,v:%d\n",s[i].l,s[i].r,s[i].v);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=cnt;++j){
			if(s[j].r>=a[i]&&s[j].v>=b[i]){
//				printf("ai:%d,bi:%d,l:%d,r:%d,k:%d\n",a[i],b[i],max(0,s[j].l-a[i]),s[j].r-a[i],s[j].v-b[i]+1);
				T2.update(1,0,N,max(0,s[j].l-a[i]),s[j].r-a[i],s[j].v-b[i]+1);
			}
		}
	}
	int ans=10000000;
	for(int i=0;i<=N;++i){
		ans=min(ans,T2.query(1,0,N,i)+i);
	}
	printf("%d\n",ans);
	return 0;
}