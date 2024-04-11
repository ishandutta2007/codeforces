#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
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
int n;
char str[200010];
int rt[400010];
struct node{
	int ls,rs,sum;
}tre[8000010];
int cnt;
int new_node(){
	return ++cnt;
}
void pushup(int p){
	tre[p].sum=tre[tre[p].ls].sum+tre[tre[p].rs].sum;
}
void insert(int &p,int l,int r,int pos){
	if(!p) p=new_node();
	if(l==r){
		tre[p].sum++;return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) insert(tre[p].ls,l,mid,pos);
	else insert(tre[p].rs,mid+1,r,pos);
	pushup(p);
}
int merge(int p,int q,int l,int r){
	if(!p||!q) return p|q;
	int x=new_node();
	if(l==r){
		tre[x].sum=tre[p].sum+tre[q].sum;return x;
	}
	int mid=l+r>>1;
	tre[x].ls=merge(tre[p].ls,tre[q].ls,l,mid);
	tre[x].rs=merge(tre[p].rs,tre[q].rs,mid+1,r);
	pushup(x);
	return x;
}
bool ask(int p,int l,int r,int L,int R){
	if(!p) return 0;
	if(L>R) return 0;
	if(l>=L&&r<=R){
		return (tre[p].sum>=1);
	}
	int mid=l+r>>1;
	bool res=0;
	if(L<=mid) res|=ask(tre[p].ls,l,mid,L,R);
	if(R>mid) res|=ask(tre[p].rs,mid+1,r,L,R);
	return res;
}
int last=1;
int pos[200010];
int tot=1;
int edpos[400010];
int mxl[400010];
int trie[400010][27];
int fa[400010];
void insert(int a,int id){
	int p=last;
//	printf("last:%d\n",last);
	mxl[++tot]=mxl[p]+1;
	pos[id]=last=tot;edpos[last]=id;
	while(p&&!trie[p][a]) trie[p][a]=last,p=fa[p];
	if(!p){
		fa[last]=1;return ;
	}
	int x=trie[p][a];
	if(mxl[x]==mxl[p]+1) fa[tot]=x;
	else{
		mxl[++tot]=mxl[p]+1;edpos[tot]=edpos[x];
		for(int i=1;i<=26;++i) trie[tot][i]=trie[x][i];
		fa[tot]=fa[x];fa[x]=fa[last]=tot;
		while(p&&trie[p][a]==x) trie[p][a]=tot,p=fa[p];
	}
}
int f[400010],g[400010];
vector<int>vec[400010];
int idx;
int ps[400010];
void dfs1(int x){
	ps[++idx]=x;
	for(int v:vec[x]) dfs1(v);
	for(int v:vec[x]) rt[x]=merge(rt[x],rt[v],1,n);
}
int main(){
	n=read();scanf("%s",str+1);
	for(int i=1;i<=n;++i) insert(str[i]-'a'+1,i);
	for(int i=1;i<=n;++i){
		insert(rt[pos[i]],1,n,i); 
	}
	for(int i=2;i<=tot;++i) vec[fa[i]].pb(i);
	dfs1(1);
	int ans=1;
	for(int i=2;i<=idx;++i){
		int p=ps[i];
//		printf("i:%d,p:%d,edp:%d,mxl:%d\n",i,p,edpos[p],mxl[p]);
		if(fa[p]==1){
			f[p]=1;g[p]=p;continue ;
		}
//		printf("dfs");
		if(ask(rt[g[fa[p]]],1,n,edpos[p]-mxl[p]+mxl[g[fa[p]]],edpos[p]-1)){
			f[p]=f[fa[p]]+1;g[p]=p;
		}
		else f[p]=f[fa[p]],g[p]=g[fa[p]];
		ans=max(ans,f[p]);
	}
	printf("%d\n",ans);
}