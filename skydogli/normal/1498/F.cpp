#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 100005
#define eps 1e-10
#define piii pair<int,pair<int,int> >
#define mp make_pair
#define x first
#define y second
#define pb push_back
int n,k,a[MN],fa[MN],f[MN][2][21];
vector<int>e[MN];
void dfs(int x){
	f[x][0][0]=a[x];
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;dfs(v);
		for(int o=0;o<2;++o){
			for(int j=0;j<k-1;++j)
				f[x][o][j+1]^=f[v][o][j];
			f[x][!o][0]^=f[v][o][k-1];
		}
	}
//	cerr<<"dfs "<<x<<": "<<f[x][0][0]<<" "<<f[x][1][0]<<endl;
}
int ans[MN];
int tmp[MN][2][25];
void work(int x){
	int res=0;
	for(int i=0;i<k;++i){
		res^=f[x][1][i];
	//	cerr<<"f "<<x<<": "<<f[x][0][i]<<" "<<f[x][1][i]<<endl;
	}
	ans[x]=(res!=0);
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i];
		if(fa[x]==v)continue;
		for(int o=0;o<2;++o)
			for(int j=0;j<k;++j)
				tmp[x][o][j]=f[x][o][j];
				
		for(int o=0;o<2;++o){
			for(int j=0;j<k-1;++j)
				f[x][o][j+1]^=f[v][o][j];
			f[x][!o][0]^=f[v][o][k-1];
		}
		
		for(int o=0;o<2;++o){
			for(int j=0;j<k-1;++j)
				f[v][o][j+1]^=f[x][o][j];
			f[v][!o][0]^=f[x][o][k-1];
		}
	//	cerr<<"fk "<<x<<" "<<v<<": "<<f[x][0][0]<<" "<<f[x][1][0]<<endl; 
		work(v);
		for(int o=0;o<2;++o)
			for(int j=0;j<k;++j)
				f[x][o][j]=tmp[x][o][j];
	}
}
signed main(){
	n=read();k=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		e[u].pb(v);
		e[v].pb(u);
	}
	for(int i=1;i<=n;++i)a[i]=read();
	dfs(1);
	work(1);
	for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
	return 0;
}