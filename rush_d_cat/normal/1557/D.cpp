#include <bits/stdc++.h>
using namespace std;
const int N = 600000 + 10;
struct Nod {
	pair<int,int> mx, lz;
} nod[N<<2];
void pushdown(int rt) {
	if (nod[rt].lz.first > 0) {
		nod[rt<<1].lz = max(nod[rt<<1].lz, nod[rt].lz);
		nod[rt<<1|1].lz = max(nod[rt<<1|1].lz, nod[rt].lz);
		nod[rt<<1].mx = max(nod[rt<<1].mx, nod[rt].lz);
		nod[rt<<1|1].mx = max(nod[rt<<1|1].mx, nod[rt].lz);
		nod[rt].lz = make_pair(0, 0);
	}
}
void update(int l,int r,int rt,int L,int R,pair<int,int> x) {
	if (L<=l&&r<=R){
		nod[rt].mx = max(nod[rt].mx, x);
		nod[rt].lz = max(nod[rt].lz, x);
		return;
	}
	int mid = (l+r)>>1;
	pushdown(rt);
	if (L<=mid) update(l,mid,rt<<1,L,R,x);
	if (R >mid) update(mid+1,r,rt<<1|1,L,R,x);
	nod[rt].mx = max(nod[rt<<1].mx, nod[rt<<1|1].mx);
}
pair<int,int> query(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R){
		return nod[rt].mx;
	}
	int mid=(l+r)>>1;
	pushdown(rt);
	pair<int,int> ans={0,0};
	if (L<=mid)ans=max(ans,query(l,mid,rt<<1,L,R));
	if (R >mid)ans=max(ans,query(mid+1,r,rt<<1|1,L,R));
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector< vector<pair<int,int> > > vec(n + 1, vector< pair<int,int> >());
	vector<int> v;

	for (int i = 0; i < m; i ++) {
		int x, l, r;
		cin >> x >> l >> r;
		v.push_back(l); v.push_back(r);
		vec[x].push_back(make_pair(l, r));
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	auto id = [&](int x) {
		return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
	};
	int tot = v.size();

	for (int i = 0; i < N<<2; i ++) nod[i].mx = nod[i].lz = {0,0};
	vector<int> pre(n+1, 0), dp(n+1, 0);
	for (int i = 1; i <= n; i ++) {
		pair<int,int> tmp;
		for (int j = 0; j < vec[i].size(); j ++) {
			vec[i][j].first = id(vec[i][j].first);
			vec[i][j].second = id(vec[i][j].second);
//printf("que %d %d\n", vec[i][j].first, vec[i][j].second);
			tmp = max(tmp, query(1,tot,1,vec[i][j].first,vec[i][j].second));
		}
//printf("tmp {%d,%d}\n",tmp.first,tmp.second);
		for (int j = 0; j < vec[i].size(); j ++) {
			update(1,tot,1,vec[i][j].first,vec[i][j].second,{tmp.first + 1, i});
		}
		pre[i] = tmp.second; dp[i] = dp[tmp.second] + 1; 
	}
	pair<int,int> bst = {0,0};
	for (int i = 1; i <= n; i ++) bst = max(bst, make_pair(dp[i], i));
	int now = bst.second;
	vector<int> vis(n + 1, 0);
	while (now) {
		vis[now] = 1; now = pre[now];
	}
	vector<int> ans;
	for (int i = 1; i <= n; i ++) if (vis[i] == 0) ans.emplace_back(i);
	cout << ans.size() << endl;
	for (auto x: ans) cout << x << " ";
	cout << endl;
}