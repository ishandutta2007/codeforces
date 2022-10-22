#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m;
int a[MN],id[MN],b[MN],vis[MN],cyc,ins[MN];
vector<int>pos[MN];
void dfs(int x){
	vis[x]=1;
	ins[x]=1;
	for(auto i:pos[x]){
			if(ins[b[i]]){
				cyc=1;
			}
			if(!vis[b[i]])dfs(b[i]);
	}
	ins[x]=0;
}
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)pos[i].clear(),vis[i]=0;
		int mx=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			pos[a[i]].push_back(i);
			if(pos[a[i]].size()>pos[mx].size())mx=a[i];
		}	
		for(int i=1;i<=n;++i)b[i]=read();
		vis[mx]=1;
		cyc=0;
		for(int i=1;i<=n;++i)if(!vis[i])dfs(i);	
		puts(cyc?"WA":"AC");
	}
	return 0;
}