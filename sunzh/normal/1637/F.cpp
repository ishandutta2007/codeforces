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
int n;
int h[200010];
vector<int>vec[200010];
int mx[200010];
long long ans;
void dfs(int x,int fa){
	mx[x]=h[x];
	int t=0;
	for(int v:vec[x]) if(v!=fa){
		dfs(v,x);
		t=max(mx[v],t);
	}
	if(h[x]>t) ans+=h[x]-t;
	mx[x]=max(mx[x],t);
}
int main(){
	n=read();
	int rt=0;
	for(int i=1;i<=n;++i) h[i]=read();
	for(int i=1;i<=n;++i) if(h[i]>h[rt]) rt=i;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v);vec[v].pb(u);
	}
	if(vec[rt].size()==1){
		++n;h[n]=h[rt];vec[n].pb(rt);vec[rt].pb(n);
	}
	int ma=0,nx=0;
	for(int i:vec[rt]){
		dfs(i,rt);
		if(mx[i]>ma) nx=ma,ma=mx[i];
		else if(mx[i]>nx) nx=mx[i];
	}
	ans+=h[rt]-ma+h[rt]-nx;
	printf("%lld\n",ans);
}