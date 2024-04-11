#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int ff[N][20],f[N],ban[N],p[N],is_dup[N],n,K,dep[N],tot;
bool need[N];
char s[N];
int ch[N][2];
#define ls ch[u][0]
#define rs ch[u][1]
void do_ban(int u){
	if(ban[u])return;
	ban[u]=1;
	if(ls)do_ban(ls);
	if(rs)do_ban(rs);
}
void dfs(int u){
	ff[u][0]=f[u];
	for(int j=1;j<=18;++j)ff[u][j]=ff[ff[u][j-1]][j-1];
	if(ls){
		f[ls]=u,dep[ls]=dep[u]+1;
		dfs(ls);
	}
	p[++tot]=u;
	if(rs){
		f[rs]=u,dep[rs]=dep[u]+1;
		dfs(rs);
	}
}
int Jump(int u){
	for(int j=18;j>=0;--j){
		if(ff[u][j]&&!is_dup[ff[u][j]])u=ff[u][j];
	}
	return u;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>K;
	cin>>(s+1);
	for(int i=1;i<=n;++i){
		cin>>ch[i][0]>>ch[i][1];
	}
	dfs(1);
	char las=0;
	for(int i=n;i>=1;--i){
		int u=p[i];
		if(s[u]!=s[p[i+1]])las=s[p[i+1]];
		if(s[u]<las)need[u]=1;
	}
	for(int i=1;i<=n;++i){
		int u=p[i];
		if(need[u]&&!ban[u]&&!is_dup[u]){
			int v=Jump(u);
			if(dep[u]-dep[v]+1<=K){
				K-=dep[u]-dep[v]+1;
				for(int x=u;;x=f[x]){
					is_dup[x]=1;
					if(x==v)break;
				}
			}
		}
		if(!is_dup[u])do_ban(u);
	}
	for(int i=1;i<=n;++i){
		int u=p[i];
		cout<<s[u];
		if(is_dup[u])cout<<s[u];
	}
	cout<<'\n';
	return 0;
}