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
#define int long long
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
int n,m;
char str[300010];
int trie[300010][27];
int fail[300010];
int val[300010],id[300010];
int cnt;
set<PII>st[300010];
vector<int>vec[300010];
int siz[300010],son[300010],top[300010],dep[300010];
int Maxn[2000010];
bool vis[300010];
int dfn[300010];
int idx;
inline void ins(int idX){
	int len=strlen(str+1);
	int p=0;
	for(int i=1;i<=len;++i){
		if(!trie[p][str[i]-'a']) trie[p][str[i]-'a']=++cnt;
		p=trie[p][str[i]-'a'];
	}
	id[idX]=p;
}
void getfail(){
	queue<int>Q;
	for(int i=0;i<26;++i) if(trie[0][i]) Q.push(trie[0][i]);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=0;i<26;++i){
			if(trie[u][i]){
				fail[trie[u][i]]=trie[fail[u]][i];Q.push(trie[u][i]);
			}
			else trie[u][i]=trie[fail[u]][i];
		}
	}
}
void dfs1(int x,int f){
//	printf("x:%d,f:%d\n",x,f);
	siz[x]=1;dep[x]=dep[f]+1;
	for(int v:vec[x]){
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]]) son[x]=v;
	}
//	printf("%d\n",son[x]);
}
void dfs2(int x,int topf){
//	printf("x:%d,topf:%d\n",x,topf);
	dfn[x]=++idx;
	top[x]=topf;
	if(son[x]!=cnt+1){
		dfs2(son[x],topf);
	}
	else return ;
	for(int v:vec[x]){
		if(v==son[x]) continue ;
		dfs2(v,v);
	}
}
void pushup(int p){
	Maxn[p]=max(Maxn[p<<1],Maxn[p<<1|1]);
}
void build(int p,int l,int r){
	if(l==r){
		if(vis[l]) Maxn[p]=0;
		else Maxn[p]=-1;return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
void update(int p,int l,int r,int pos,int k){
	if(l==r){Maxn[p]=k; return ;}
	int mid=l+r>>1;
	if(pos<=mid) update(p<<1,l,mid,pos,k);
	else update(p<<1|1,mid+1,r,pos,k);
	pushup(p); 
}
int query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return Maxn[p];
	int mid=l+r>>1;
	int res=-1;
	if(L<=mid)res=max(res,query(p<<1,l,mid,L,R));
	if(R>mid) res=max(query(p<<1|1,mid+1,r,L,R),res);
	return res;
}
int qry(int x,int y){
	int res=-1;
	while(top[x]!=top[y]){
//		printf("x:%d,y:%d\n",x,y);
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		res=max(res,query(1,1,idx,dfn[top[x]],dfn[x]));
		x=fail[top[x]];
	}
	if(x==y) return res;
	if(dep[x]>dep[y]) swap(x,y); 
	res=max(res,query(1,1,idx,dfn[x],dfn[y]));return res;
}
signed main(){
	memset(siz,-1,sizeof(siz));
	memset(Maxn,-1,sizeof(Maxn));
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",str+1);ins(i);
	}
	getfail();
	for(int i=1;i<=cnt;++i) vec[fail[i]].pb(i);
	for(int i=0;i<=cnt;++i) son[i]=cnt+1;
	dfs1(0,0);
	dfs2(0,0);
//	printf("%d\n",siz[son[1]]);
	for(int i=1;i<=n;++i) vis[dfn[id[i]]]=1;
	build(1,1,idx);
	while(m--){
		int op=read();
		if(op==1){
			int i=read(),x=read();
			st[id[i]].erase(mp(-val[i],i));
			st[id[i]].insert(mp(-x,i));val[i]=x;
			auto it=st[id[i]].begin();
			update(1,1,idx,dfn[id[i]],-(it->fi));
		}
		else{
			scanf("%s",str+1);
			int len=strlen(str+1);
			int p=0;
			int maxn;maxn=-1;
			for(int i=1;i<=len;++i){
				p=trie[p][str[i]-'a'];
				int res=qry(0,p);
				maxn=max(maxn,res);
			}
			printf("%lld\n",maxn);
		}
	}
}