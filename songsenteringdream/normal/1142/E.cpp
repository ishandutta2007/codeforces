#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int o=1e5+10;
int n,m,h[o],cnt,d[o],scc[o],sccn,dfn[o],low[o],st[o],tp,p,ans;bool vis[o];vector<int> vec[o];queue<int> q;
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void tarjan(int nw){
	dfn[nw]=low[nw]=++cnt;vis[st[++tp]=nw]=1;
	for(int i=h[nw];i;i=e[i].p)
		if(!dfn[e[i].v]) tarjan(e[i].v),low[nw]=min(low[nw],low[e[i].v]);
		else if(vis[e[i].v]) low[nw]=min(low[nw],dfn[e[i].v]);
	if(dfn[nw]==low[nw]) for(++sccn;st[tp+1]^nw;vis[st[tp--]]=0) vec[scc[st[tp]]=sccn].push_back(st[tp]);
}
inline void del(int id){
	for(int i=vec[id].size();i--;) for(int j=h[vec[id][i]];j;j=e[j].p)
		if(id-scc[e[j].v]&&!--d[scc[e[j].v]]) q.push(scc[e[j].v]);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;++i) cin>>u>>v,ad(u,v);
	for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;++i) for(int j=h[i];j;j=e[j].p) if(scc[i]^scc[e[j].v]) ++d[scc[e[j].v]];
	for(int i=1;i<=sccn;++i) if(!d[i]) q.push(i);
	ans=q.front();q.pop();
	for(int i,j,s1,s2,x;!q.empty();q.pop()){
		for(i=0,s1=vec[q.front()].size(),j=p,s2=vec[ans].size();i<s1&&j<s2;){
			cout<<"? "<<vec[q.front()][i]<<" "<<vec[ans][j]<<endl;cin>>x;
			if(x) ++j;else ++i;
		}
		if(i==s1) p=j,del(q.front());
		else del(ans),ans=q.front(),p=i;
	}
	cout<<"! "<<vec[ans][p]<<endl;
	return 0;
}