#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n;
int t[200010],h[200010];
int in[200010],out[200010];
bool con[200010];
int ans=0;
int tot;
int head[200010],nxt[400010],to[400010];
int f[200010],g[200010];
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int fa){
	con[x]=0;
	bool fl=0;
	vector<int>vec;
	int sum=0;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];if(!con[v]) continue ;
		fl=1;dfs(v,x);vec.push_back(f[v]-g[v]);sum+=g[v];
	}
	if(!fl) f[x]=min(in[x]+1,out[x])*t[x],g[x]=min(in[x],out[x]+1)*t[x];
	else{
		sort(vec.begin(),vec.end(),cmp);
		if(fa==0){
			int s=vec.size();
			int res=sum+min(in[x]+s,out[x])*t[x];
			for(int i=0;i<vec.size();++i){
				sum+=vec[i];
				res=max(res,sum+min(in[x]+(s-i-1),out[x]+i+1)*t[x]);
			}
			ans-=res;
		}
		else{
			int s=vec.size();
			f[x]=sum+min(in[x]+s+1,out[x])*t[x];g[x]=sum+min(in[x]+s,out[x]+1)*t[x];
			for(int i=0;i<vec.size();++i){
				sum+=vec[i];
				f[x]=max(f[x],sum+min(in[x]+s-i,out[x]+i+1)*t[x]);
				g[x]=max(g[x],sum+min(in[x]+s-i-1,out[x]+i+2)*t[x]);
			} 
		}
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) t[i]=read();
	for(int i=1;i<=n;++i) h[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		if(h[u]==h[v]){
			con[u]=con[v]=1;add(u,v),add(v,u);
		}
		else{
			if(h[u]>h[v]) swap(u,v);
			++in[v],++out[u];
		}
		ans+=t[u]+t[v];
	}
	for(int i=1;i<=n;++i) if(!con[i]) ans-=min(in[i],out[i])*t[i];
	for(int i=1;i<=n;++i){
		if(con[i]) dfs(i,0);
	} 
	print(ans);
}