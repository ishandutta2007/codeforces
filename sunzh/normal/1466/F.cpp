#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
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
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
vector<int>p[500010];
int fa[500010];
int id[500010];
vector<int>ans;
const int mod=1e9+7;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		int k=read();
		for(int j=1;j<=k;++j){
			p[i].pb(read());
		}
		sort(p[i].begin(),p[i].end());
	}
	for(int i=1;i<=m+1;++i) fa[i]=i;
	for(int i=1;i<=n;++i){
		p[i][0]=find(p[i][0]);
		if(p[i].size()>1){
			p[i][1]=find(p[i][1]);
			sort(p[i].begin(),p[i].end());
			if(p[i][0]==p[i][1]) continue ;
			id[p[i][0]]=i;
			ans.pb(i);
			fa[p[i][0]]=p[i][1];
		}
		else{
			if(p[i][0]==m+1) continue ;
			id[p[i][0]]=i;ans.pb(i);fa[p[i][0]]=m+1;
		}
	}
	auto qpow=[&](int x,int k){
		int res=1;
		while(k){
			if(k&1) res=1ll*res*x%mod;
			x=1ll*x*x%mod;k>>=1;
		}
		return res;
	};
	printf("%d %d\n",qpow(2,ans.size()),ans.size());
	for(int x:ans) printf("%d ",x);
}