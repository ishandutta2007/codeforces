#include<cstdio>
#include<vector>
using namespace std;
const int o=1e6;
int T,n,h[o],cnt,parity[o];bool flg;
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void Dfs(int nw,int fa){
	int odd=0,even=0;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa){
		Dfs(e[i].v,nw);
		if(parity[e[i].v]) ++odd;
		else ++even;
	}
	if(nw>1){
		if(even<odd) ++even,parity[nw]=0;
		else ++odd,parity[nw]=1; 
	}
	if(odd-even&&odd-1-even) flg=1;
}
void dfs(int nw,int fa);
inline void cut(int nw,int fa,int v){
	if(v==fa) printf("%d %d\n",nw,v);
	else dfs(v,nw);
}
void dfs(int nw,int fa){
	int p=0;vector<int> odd,even;
	for(int i=h[nw];i;i=e[i].p)
		if(e[i].v^fa) if(parity[e[i].v]) odd.push_back(e[i].v);else even.push_back(e[i].v);
		else if(parity[nw]) odd.push_back(fa);else even.push_back(fa);
	if(odd.size()>even.size()) cut(nw,fa,odd[0]),p=1;
	for(int i=0,sz=even.size();i<sz;++i) cut(nw,fa,even[i]),cut(nw,fa,odd[p++]);
}
int main(){
	for(scanf("%d",&T);T--;cnt=flg=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) h[i]=0;
		for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),ad(u,v),ad(v,u);
		Dfs(1,0);
		if(flg){printf("NO\n");continue;}
		printf("YES\n");
		dfs(1,0);
	}
	return 0;
}