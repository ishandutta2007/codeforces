#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 100005
int n,m,block,aa[100005],a[100005],f[100005],h[100005],num,answer[100005],ans[100005];
int in[100005],out[100005],dfn,fa[100005];
bool vis[100005];
struct query{
	int l,r,k,id,block;
}q[N];
struct edge{
	int to,next;
}data[N];
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+c-'0';
		c=getchar();
	}
}
void dfs(int x){
	in[x]=++dfn;
	int y;
	for(int i=h[x];i;i=data[i].next){
		y=data[i].to;
		if(fa[x]==y){
			continue;
		}
		fa[y]=x;
		dfs(y);
	}
	out[x]=dfn;
}
inline bool cmp(query x,query y){
	return x.block==y.block?x.r<y.r:x.block<y.block;
}
inline void update(int x){
	if(vis[x]){
		ans[f[a[x]]--]--;
	}
	else{
		ans[++f[a[x]]]++;
	}
	vis[x]^=1;
}
int main(){
	read(n);
	read(m);
	block=sqrt(n);
	int x,y;
	for(int i=1;i<=n;i++){
		read(aa[i]);
	}
	for(int i=1;i<n;i++){
		read(x),read(y);
		data[++num].to=y;
		data[num].next=h[x];
		h[x]=num;
		data[++num].to=x;
		data[num].next=h[y];
		h[y]=num;
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		a[in[i]]=aa[i];
	}
	for(int i=1;i<=m;i++){
		read(x);
		q[i].l=in[x];
		q[i].r=out[x];
		read(q[i].k);
		q[i].id=i;
		q[i].block=(q[i].l-1)/block;
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		for(;l<q[i].l;l++){
			update(l);
		}
		for(;l>q[i].l;l--){
			update(l-1);
		}
		for(;r<q[i].r;r++){
			update(r+1);
		}
		for(;r>q[i].r;r--){
			update(r);
		}
		answer[q[i].id]=ans[q[i].k];
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",answer[i]);
	}
	return 0;
}