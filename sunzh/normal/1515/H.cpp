#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,q;
int a[200010];
int cnt=1,rt=1;
int siz[8000010];
int trie[8000010][2];
int tag[8000010],tb[8000010],t0[8000010],t1[8000010];
void pushup(int p){
	siz[p]=siz[trie[p][0]]+siz[trie[p][1]];
	t0[p]=t0[trie[p][0]]|t0[trie[p][1]];
	t1[p]=t1[trie[p][0]]|t1[trie[p][1]];
}
void pushxor(int p,int x){
	if(!p) return ;
	tag[p]^=x;
	if(tb[p]!=-1&&x>>tb[p]&1) swap(trie[p][0],trie[p][1]);
	int a=(t0[p]&(~x))|(t1[p]&x),y=(t0[p]&x)|(t1[p]&(~x));
	t0[p]=a,t1[p]=y;
}
void pushdown(int p,int bit){
	if(tag[p]){
		pushxor(trie[p][0],tag[p]);
		pushxor(trie[p][1],tag[p]);
		tag[p]=0;
	}
}
map<int,int>Map;
void insert(int x){
	if(Map.count(x)) return ;
	Map[x]=1;
	int pos=rt;tb[rt]=20;++siz[rt];
	for(int i=19;i>=0;--i){
		tb[pos]=i;
		t1[pos]|=x;
		t0[pos]|=((1<<20)-1)^x;
		if(x&(1<<i)){
			if(trie[pos][1]) pos=trie[pos][1];
			else pos=trie[pos][1]=++cnt;
		}
		else {
			if(trie[pos][0]) pos=trie[pos][0];
			else pos=trie[pos][0]=++cnt;
		}
		++siz[pos];
	}
	t1[pos]|=x;
	t0[pos]|=((1<<20)-1)^x;
	tb[pos]=-1;
	
}
void split(int &p,int &q,int l,int r,int L,int R){
	if(!p||R<l||L>r) return ;
	if(l>=L&&r<=R){
//		printf("p:%d,l:%d,r:%d,%d %d\n",p,l,r,t0[p],t1[p]);
		q=p;p=0;return ;
	}
	int mid=l+r>>1;
	pushdown(p,tb[p]);
	q=++cnt;tb[q]=tb[p];
	split(trie[p][0],trie[q][0],l,mid,L,R);
	split(trie[p][1],trie[q][1],mid+1,r,L,R);
	if(tb[p]!=-1)pushup(p),pushup(q);
}
void merge(int &p,int q){
	if(!p||!q){
		p=p|q;return ;
	}
	pushdown(p,tb[p]);pushdown(q,tb[q]);
	merge(trie[p][0],trie[q][0]);
	merge(trie[p][1],trie[q][1]);
	if(tb[p]!=-1) pushup(p);
}
void pushor(int p,int x){
//	printf("p:%d,x:%d\n",p,x);
	if(!p) return ;
	if(!(x&t0[p]&t1[p])){
//		printf("%d\n",t0[p]);
//		printf("%d\n",x&t0[p]);
		pushxor(p,x&t0[p]);
		return ;
	}
	pushdown(p,tb[p]);
	if(x>>tb[p]&1) pushxor(trie[p][0],1<<tb[p]),merge(trie[p][1],trie[p][0]),trie[p][0]=0;
//	x&=((1<<tb[p])-1);
	pushor(trie[p][0],x);pushor(trie[p][1],x);
	pushup(p);
}
int query(int p,int l,int r,int L,int R){
	if(!p) return 0;
	if(l>=L&&r<=R) return siz[p];
	int mid=l+r>>1,res=0;
	pushdown(p,tb[p]);
	if(L<=mid) res+=query(trie[p][0],l,mid,L,R);
	if(R>mid) res+=query(trie[p][1],mid+1,r,L,R);
	return res;
}
//void dfs(int x,int l,int r){
//	if(!x) return ;
////	if(l==r) printf("x:%d,l:%d,r:%d\n",x,l,r);
//	int mid=l+r>>1;
//	pushdown(x,tb[x]);
//	dfs(trie[x][0],l,mid);
//	dfs(trie[x][1],mid+1,r);
//}
int main(){
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read(),insert(a[i]);
	
	while(q--){
		int t=read();
		if(t==4){
			int l=read(),r=read();
			printf("%d\n",query(rt,0,(1<<20)-1,l,r));
		}
		else{
			int l=read(),r=read(),x=read();
			int q;split(rt,q,0,(1<<20)-1,l,r);
//			printf("q:%d,%d\n",q,siz[q]);
//			printf("%d %d\n",rt,siz[rt]);
//			printf("%d %d\n",t0[q],t1[q]);
			if(t==1) pushxor(q,(1<<20)-1),pushor(q,x^((1<<20)-1)),pushxor(q,(1<<20)-1);
			else if(t==2) pushor(q,x);
			else pushxor(q,x);
			merge(rt,q);
		}
//		dfs(rt,0,(1<<20)-1);
	}
}