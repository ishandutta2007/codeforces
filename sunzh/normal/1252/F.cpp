#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define int long long
#define PII pair<int,int>
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(long long x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int head[500010],nxt[1000010],to[1000010];
int tot;
int fa[500010];
int dep[500010];
int rt;
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
vector<PII>dsu[500010];
struct node{
	int sum,id,cnt;
};
vector<node> dfs(int x,int f){
	vector<node>res;dep[x]=dep[f]+1;
	res.clear();
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue ;
		vector<node>kid=dfs(v,x);
		if(kid.size()>res.size()) swap(kid,res);
		int ir=res.size(),ik=kid.size();
		for(int j=1;j<=ik;++j){
			res[ir-j].sum+=kid[ik-j].cnt*dep[x];
			kid[ik-j].sum+=res[ir-j].cnt*dep[x];
			dsu[res[ir-j].id].eb(kid[ik-j].id,kid[ik-j].sum-res[ir-j].sum);
			res[ir-j].cnt+=kid[ik-j].cnt;
		}
	}
	res.pb(node{dep[x]-1,x,1});
	return res;
}
int ans[500010];
void getans(int x,int sum){
	ans[x]=sum+ans[fa[x]];
	for(auto i:dsu[x]){
		getans(i.fi,i.se+sum);
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		int f=read();
		fa[i]=f;
		if(f==0) rt=i;
		else add(f,i);
	}
	vector<node>res=dfs(rt,0);
	reverse(res.begin(),res.end());
	for(auto i:res){
		getans(i.id,i.sum);
	}
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
	return 0;
}