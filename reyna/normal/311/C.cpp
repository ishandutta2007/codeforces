//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
const int N = 1e6 + 9;
const int K = 1e5 + 9;

ll dis[K];
bool vis[K];
pair<ll,ll> t[4 * N];
ll is[N];
vector<pair<ll,ll> > al[K];
ll h,n,m,k; 
ll a[N],c[N];
void update(int idx,ll x,int v = 1,int b = 0,int e = n-1) {
	if(b == e) {
		if(x == -1) idx = -1,x = 0;
		t[v] = {x,-idx};
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	if(mid + 1 > idx) update(idx,x,l,b,mid);
	else update(idx,x,r,mid+1,e);
	t[v] = max(t[l],t[r]);
	return;
}
set<pair<ll,ll> > st;
void relax(int v) {
	vis[v] = 1;
	for(int i = 0; i < al[v].size();i++) {
		int u = al[v][i].first;
		if(vis[u]) continue;
		st.erase({dis[u],u});
		dis[u] = min(dis[u],dis[v] + al[v][i].second);
		st.insert({dis[u],u});
	}
	return;
}
void dj() {
	memset(vis,0,sizeof vis);
	relax(1);
	while(st.size()) {
		pair<ll,ll> cur = *(st.begin());
		ll v = cur.second;
		st.erase(cur);
		if(vis[v]) continue;
		relax(v);
	}
	return;
}
main() {
	ios_base::sync_with_stdio(0);
	cin >> h >> n >> m >> k;
	fill(dis,dis+K,2e18);
	if(k == 1) {
		dis[0] = 0;
	}
	for(int i = 0; i < N;i++) t[i].second = 1;
	dis[1] = 0;
	for(int i = 0; i < n;i++) cin >> a[i] >> c[i];
	for(int i = 0; i < n;i++) if(a[i] % k == 1) is[i] = 1,update(i,c[i]);
	while(m--) {
		int cq; cin >> cq;
		if(cq == 1) {
			ll x; cin >> x;
			for(int i = 0; i < k;i++) al[i].push_back({(x + i) % k,x});
			fill(dis,dis+K,2e18);
			dis[1] = 0;
			dj();
			if(k == 1) dis[0] = 0;
			for(int i = 0; i < n;i++) {
				if(dis[a[i] % k] <= a[i]) {
					is[i] = 1;
					update(i,c[i]);
				}
			}
		} else if(cq == 2) {
			int v,x; cin >> v >> x; --v;
			c[v] -= x;
			if(is[v]) update(v,c[v]);
		} else {
			cout << max(t[1].first,(ll)0) << '\n';
			if(t[1].second == 1) continue;
			c[-t[1].second] = -1;
			update(-t[1].second,-1);
		}
	}
}