#include<cstdio>
#include<set>
using namespace std;
const int o=2e5+10;
int n,h[o],cnt,a[o],b[o],ans;set<int> S[o];
struct Edge{int v,p;}e[o*2];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw,int fa){
	bool flg=0;
	S[nw].insert(b[nw]);
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa){
		b[e[i].v]^=b[nw];dfs(e[i].v,nw);
		if(S[nw].size()<S[e[i].v].size()) swap(S[nw],S[e[i].v]);
		for(set<int>::iterator iter=S[e[i].v].begin();iter!=S[e[i].v].end();++iter)
			flg|=(S[nw].find((*iter)^a[nw])!=S[nw].end());
		for(;!S[e[i].v].empty();S[e[i].v].erase(S[e[i].v].begin())) S[nw].insert(*S[e[i].v].begin());
	}
	if(flg) S[nw].clear(),++ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=a[i];
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),ad(u,v),ad(v,u);
	dfs(1,0);
	printf("%d",ans);
	return 0;
}