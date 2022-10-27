#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,q;
map< pair<int,int>, vector<int> > vec;
vector< pair<int,int> > nod[N<<2];
void update(int l,int r,int rt,int L,int R,pair<int,int> x) {
	if(L<=l&&r<=R) {
		nod[rt].push_back(x); return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) update(l,mid,rt<<1,L,R,x);
	if(R >mid) update(mid+1,r,rt<<1|1,L,R,x);
}

int par[N], sz[N], dis[N];
int find(int x) {
	return par[x]==x?x:find(par[x]);
}
int query(int x) {
	return par[x]==x?0:dis[x]^query(par[x]);
}

bool unite(int u,int v,vector< pair<int, vector<int> > > & stk) {	
	int fu = find(u);
	int fv = find(v);
	if (fu == fv) {
		if(query(u) == query(v)) return false;
	}
	if(sz[fu] > sz[fv]) swap(fu, fv);
	vector<int> tmp; tmp.push_back(dis[fu]); tmp.push_back(sz[fu]); tmp.push_back(par[fu]);
	stk.push_back(make_pair(fu, tmp));
	tmp.clear(); tmp.push_back(dis[fv]); tmp.push_back(sz[fv]); tmp.push_back(par[fv]);
	stk.push_back(make_pair(fv, tmp));
	dis[fu] = 1 ^ query(u) ^ query(v);
	sz[fv] += sz[fu];
	par[fu] = fv;
	return true;
}
bool add(int rt, vector< pair<int, vector<int> > > & stk) {
	bool ok = 1;
	for(auto p: nod[rt]) {
		ok &= unite(p.first, p.second, stk);
	}
	return ok;
}
void roll(vector< pair<int, vector<int> > > & stk) {
	for (auto p: stk) {
		int id = p.first;
		dis[id] = p.second[0];
		sz[id] = p.second[1];
		par[id] = p.second[2];
	}
	stk.clear();
}
bool gg[N];
void solve(int l,int r, int rt){
	vector< pair<int, vector<int> > > stk;
	bool res = add(rt, stk);
	if (res == false) {
		for(int i=l;i<=r;i++) gg[i]=1;
		roll(stk); return;
	}
	if(l==r){
		roll(stk); return;
	}	
	int mid=(l+r)>>1;
	solve(l,mid,rt<<1);
	solve(mid+1,r,rt<<1|1);
	roll(stk);
}
int main() {
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		sz[i]=1; par[i]=i; dis[i]=0;
	}
	for(int i=1;i<=q;i++) {
		int x,y; scanf("%d%d",&x,&y);
		vec[make_pair(x,y)].push_back(i);
	}	
	for(auto p: vec) {
		p.second.push_back(q+1);
		for(int i=0;i+1<p.second.size();i+=2){
			int l=p.second[i];
			int r=p.second[i+1]-1;
			update(1,q,1,l,r,p.first);
		}
	}
	solve(1,q,1);
	for(int i=1;i<=q;i++)
		printf("%s\n", gg[i]?"NO":"YES");

}