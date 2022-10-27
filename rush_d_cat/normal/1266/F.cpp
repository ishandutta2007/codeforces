#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
const int N = 1000000 + 10;
vector<int> g[N];
vector< pair<int,int> > vec[N];
int n,up[N],down[N],par[N];
void dfs1(int u,int p){
	par[u]=p;
	for(auto v:g[u]){
		if(v==p)continue;
		dfs1(v,u);
		down[u]=max(down[v]+1,down[u]);
	}
}
void dfs2(int u,int p){
	multiset<int> st;
	for(auto v:g[u]){
		if(v==p)continue;
		st.insert(down[v]+1);
	}
	for(auto v:g[u]){
		if(v==p)continue;
		st.erase(st.find(down[v]+1));
		up[v]=max(up[v],up[u]+1);
		if(st.size()) up[v]=max(up[v],(*st.rbegin())+1);
		dfs2(v,u);
		st.insert(down[v]+1);
	}
}
int ans[N];
void upd(int u) {
	//printf("upd %d\n", u);
	vector<int> sum((int)vec[u].size()+2, 0);
	for(int i=(int)vec[u].size()-1;i>=0;i--){
		sum[i]=sum[i+1]+vec[u][i].second;
	}
	// x-1 x x x   for odd
	for(int i=(int)vec[u].size()-1;i>=0;i--){
		int val=sum[i+1] + 1;
		int pos=2*vec[u][i].first+1;
		//printf("val=%d,pos=%d\n", val,pos);
		ans[pos]=max(ans[pos],val);
		if(pos>=2) ans[pos-2]=max(ans[pos-2], sum[i]);
	}
	// x+1 x x x  for even
	for(int i=(int)vec[u].size()-1;i>=0;i--){
		int val=sum[i];
		int pos=2*vec[u][i].first;
		ans[pos]=max(ans[pos],val);
	}
}
void upd(int u, int v) {
	int i=(int)vec[u].size()-1,j=(int)vec[v].size()-1;
	int s1=0,s2=0;
	//printf("u=%d,v=%d,%d %d\n", u,v,i,j);
	while(1){
		if(i==-1 && j==-1) break;
		//printf("i=%d,j=%d\n", i,j);
		if((j==-1 || vec[u][i].first > vec[v][j].first) && (i!=-1)) {
			int pos=2*vec[u][i].first; s1+=vec[u][i].second;
			int val=s1+s2;
			//printf("pos=%d,val=%d\n", pos,val);
			ans[pos]=max(ans[pos],val-2);
			i--;
		} else
		if((i==-1|| vec[u][i].first <= vec[v][j].first) && (j!=-1)) {
			int pos=2*vec[v][j].first; s2+=vec[v][j].second;
			int val=s1+s2;
			//printf("pos=%d,val=%d\n", pos,val);
			ans[pos]=max(ans[pos],val-2);
			j--;
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs1(1,1); dfs2(1,1);
	int mx=0;
	for(int i=1;i<=n;i++)mx=max(mx,(int)g[i].size()+1);
	printf("%d", mx);
	for(int i=1;i<=n;i++){
		map<int,int> mp;
		for(auto v:g[i]){
			if(v==par[i]) mp[up[i]]++;
			else mp[down[v]+1]++;
		}
		for(auto p: mp) {
			vec[i].push_back(p);
		}
	}
	for(int i=1;i<=n;i++){
		//printf("i=%d: ", i);
		//for(auto p: vec[i]) printf("(%d, %d) ", p.first,p.second); printf("\n");
	}
	for(int i=1;i<=n;i++){
		upd(i);
		for(auto v:g[i]){
			if(v==par[i])continue;
			upd(i,v);
		}
	}
	for(int i=n;i>=2;i--){
		ans[i]=max(ans[i],ans[i+2]);
	}
	for(int i=2;i<=n;i++){
		printf(" %d", max(ans[i],1));
	}
	printf("\n");
}