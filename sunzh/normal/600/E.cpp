#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
int inline read(){
	int num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return num*neg;
}
int n,tot;
int c;
int head[100010],nxt[200010],to[200010];
int col[100010],ans[100010];
int rt[100010],ls[2000010],rs[2000010];
int sum[2000010],cnt[2000010];
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
void pushup(int p){
	if(cnt[ls[p]]>cnt[rs[p]]){
		cnt[p]=cnt[ls[p]];
		sum[p]=sum[ls[p]];
	}
	else if(cnt[ls[p]]<cnt[rs[p]]){
		cnt[p]=cnt[rs[p]],sum[p]=sum[rs[p]];
	}
	else{
		cnt[p]=cnt[rs[p]];
		sum[p]=sum[ls[p]]+sum[rs[p]];
	}
}
void update(int &p,int l,int r,int ps){
	if(!p) p=++c;
	if(l==r){
		sum[p]=ps,cnt[p]=1;
		return ;
	}
	int mid=l+r>>1;
	if(ps<=mid) update(ls[p],l,mid,ps);
	else update(rs[p],mid+1,r,ps);
	pushup(p);
}
int merge(int x,int y,int l,int r){
	if(!x||!y) return x|y;
	if(l==r){
		cnt[x]+=cnt[y];
		return x;
	}
	int mid=l+r>>1;
	ls[x]=merge(ls[x],ls[y],l,mid);
	rs[x]=merge(rs[x],rs[y],mid+1,r);
	pushup(x);
	return x;
}
void dfs(int x,int fa){
	update(rt[x],1,100000,col[x]);
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue ;
		dfs(v,x);
		rt[x]=merge(rt[x],rt[v],1,100000);
	}
	ans[x]=sum[rt[x]];
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) col[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
	return 0; 
}