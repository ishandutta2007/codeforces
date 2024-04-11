// 0:24
#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
vector<int> g[N];
int n,sz[N],son[N],ans[N];
multiset<int> s1,s2,s3;
void pre(int u,int p){
	sz[u]=1;
	for(auto v:g[u]){
		if(v==p)continue;
		pre(v,u);
		sz[u]+=sz[v];
	}
}
void add(int u,int p,int x){
	if(x==1) {
		s1.insert(sz[u]);
		s2.erase(s2.find(sz[u]));
	} else {
		s1.erase(s1.find(sz[u]));
		s2.insert(sz[u]);
	}
	for(auto v:g[u]){
		if(v==p||son[v])continue;
		add(v,u,x);
	}
}
bool cmp(pair<int,int> x,pair<int,int> y){
	return x>y;
}
int cac(int sz1,int sz2,int sz3,int x){
	//printf("x=%d\n", x);
	return max(max(sz1-x, sz2),sz3+x);
}
int solve(int sz1, int sz2, int sz3, multiset<int>& st, int lz) {
	vector<int> v;
	v.push_back(sz1 - sz2);
	v.push_back((sz1 - sz3) / 2);
	int ans = 1e9;

	for (auto x: v) {
		//printf("x = %d, x + lz = %d\n", x, x+lz);
		auto it = st.lower_bound(x+lz);
		//printf("*it = %d\n", *it);
		if (it != st.end()) {
			//printf("* it = %d\n", *it);
			ans=min(cac(sz1,sz2,sz3,(*it)-lz),ans);
		}
		if (it != st.begin()) {
			--it;
			ans=min(cac(sz1,sz2,sz3,(*it)-lz),ans);
		}
	}
	return ans;
}
void dfs(int u,int p,int keep){
	//printf("dfs %d %d %d\n", u,p,keep);
	s3.insert(sz[u]);
	if(u!=p) s2.erase(s2.find(sz[p]));
	int bigchild = -1;
	for(auto v: g[u]) {
		if(v==p)continue;
		if(bigchild == -1 || sz[v] > sz[bigchild]) {
			bigchild = v;
		}
	}
	for(auto v: g[u]) {
		if(v==p||v==bigchild)continue;
		dfs(v,u,0);
	}

	if(bigchild != -1){
		dfs(bigchild,u,1); son[bigchild] = 1; 
	}
	ans[u] = 0;
	vector< pair<int,int> > vec;
	for(auto v:g[u]) {
		if(v==p) {
			vec.push_back(make_pair(n-sz[u], v));
		} else {
			vec.push_back(make_pair(sz[v], v));
		}
		ans[u] = max(ans[u], vec.back().first);
	}
	sort(vec.begin(),vec.end(),cmp);

	if (vec[0].second != p) {
		ans[u] = min(solve(vec[0].first, vec[1].first, vec.back().first, s1, 0),ans[u]);
	}
	
	add(u,p,1);
	if (bigchild != -1) son[bigchild] = 0;
	if (vec.size() == 1) {
		ans[u] = n - 1;
	} else {
		if (vec[0].second == p) {
			ans[u] = min(solve(vec[0].first, vec[1].first, vec.back().first, s2, 0),ans[u]);
			ans[u] = min(solve(vec[0].first, vec[1].first, vec.back().first, s3, sz[u]), ans[u]);
		}
	}
	if(keep==0) add(u,p,-1);
	s3.erase(s3.find(sz[u]));
	if(u!=p) s2.insert(sz[p]);
}
int main() {
	scanf("%d",&n);
	int rt;
	for(int i=1;i<=n;i++){
		int u,v; scanf("%d%d",&u,&v);
		if(min(u,v)==0){
			rt=max(u,v); continue;
		}
		g[u].push_back(v); g[v].push_back(u);
	}
	pre(rt,rt);
	if(n==1)return !printf("0\n");
	for(int i=1;i<=n;i++) s2.insert(sz[i]);
	dfs(rt,rt,0);
	for(int i=1;i<=n;i++) printf("%d\n", ans[i]);
}