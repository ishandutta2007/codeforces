#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
int n,q,k;
int now=1;


int sz[N], par[N];
int find(int x) {
	return par[x]==x?x:find(par[x]);
}
pair<int, pair<int,int> > stk[10000000 + 10]; int top = 0;
void add(int u,int v){
	int pu=find(u);
	int pv=find(v);
	if(pu==pv)return;
	if(sz[pu]>sz[pv]) swap(pu,pv);
	stk[++top] = make_pair(pv, make_pair(sz[pv], par[pv]));
	sz[pv]+=sz[pu]; 
	stk[++top] = make_pair(pu, make_pair(sz[pu], par[pu]));
	par[pu]=pv;
}
void roll(int cnt) {
	for(int i=1;i<=cnt;i++){
		sz[ stk[top].first ] = stk[top].second.first;
		par[ stk[top].first ] = stk[top].second.second;
		-- top;
	}
}

vector< pair<int,int> > addedge, nods[N<<2];
pair<int,int> querys[N]; int tot = 0, mp[N],ans[N];

void update(int l,int r,int rt,int L,int R,pair<int,int> edge) {
	if(L<=l&&r<=R){
		//printf("edge(%d,%d) [%d,%d]\n", edge.first,edge.second,l,r);
		nods[rt].push_back(edge); return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) update(l,mid,rt<<1,L,R,edge);
	if(R >mid) update(mid+1,r,rt<<1|1,L,R,edge);
}

void solve(int l,int r,int rt){
	int beg = top;
	for(auto e: nods[rt]) {
		//printf("link %d %d\n", e.first, e.second);
		add(e.first, e.second);
	}
	int end = top;
	int cnt = end - beg;

	if(l==r){
		//printf("ans l=%d\n", l);
		if(l<=tot) {
			//printf("ans l = %d: ", querys[l].second);
			//printf("%d\n", sz[find(querys[l].second)]);
			ans[mp[l]] = sz[find(querys[l].second)];
		}
		for(auto e: nods[rt]) {
			//printf("del %d %d\n", e.first, e.second);
		}
		roll(cnt); return;
	}
	int mid=(l+r)>>1;
	solve(l,mid,rt<<1);
	solve(mid+1,r,rt<<1|1);
	for(auto e: nods[rt]) {
		//printf("del %d %d\n", e.first, e.second);
	}
	roll(cnt);
	if(cnt)
	for(int i=1;i<=n;i++){
		//printf("i=%d,sz=%d,par=%d\n", i,sz[find(i)],par[find(i)]);
	}
}

int op[N],x[N],y[N];
int main() {
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++){
		par[i]=i; sz[i]=1;
	}
	int las = 1;
	int mx = 500000;
	for(int i=1;i<=q;i++){
		scanf("%d",&op[i]);
		if(op[i]==2) scanf("%d",&x[i]);
		if(op[i]==1) {
			scanf("%d%d",&x[i],&y[i]);
		}
		//printf("i=%d\n", i);
	}
	//printf("ok\n");
	for(int i=q,j=q;i>=1;i=j){
		if(op[j]==3){
			++now; --j; continue;
		}
		while(j>=1 && op[j]!=3) --j;
		//printf("[%d,%d)\n", i,j);

		for(int pos=i;pos>=j+1;pos--){
			if(op[pos]==3) {
				++now;
			}else if(op[pos]==2) {
				querys[++tot] = make_pair(now,x[pos]); mp[tot]=pos;
			}else{
				while(las<=tot && querys[las].first <= now - k) ++ las;
				if(las<=tot) update(1,mx,1,las,tot,make_pair(x[pos],y[pos]));
			}	
		}
	}
	solve(1,mx,1);
	for(int i=1;i<=q;i++) 
		if(ans[i])
		printf("%d\n", ans[i]);
}