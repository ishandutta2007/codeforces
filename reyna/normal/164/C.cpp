//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 6060;
int s[N],t[N],c[N],ct[N],cp[N],to[N],eid[N],head[N],pre[N];
int cnt,vn;
int dis[N];
vector<int> ver,tver;
pair<int,int> par[N];
map<int,int> mp;
void do_mincost() {
	for(int i = 0; i < ver.size();++i) dis[i] = -1e9 - 7,par[i] = {-1,-1};
	dis[0] = 0;
	int n = ver.size();
	int m = ver.size() + vn - 1;
	int x = n - 1;
	while(x--) {
		for(int i = 0; i < 2 * m; ++i) {
			if(cp[i] > 0) {
				int e = i >> 1;
				int u = s[e], v = t[e];
				if(i & 1) swap(u,v);
				if(dis[u] + ct[i] > dis[v]) {
					dis[v] = dis[u] + ct[i];
					par[v] = {u,i};
				}
			}
		}
	}
	int cur = n - 1;
	while(cur != -1) {
		int e = par[cur].second;
		int next = par[cur].first;
//	cout << cur << ' ' << next << endl;
		if(next == -1) break;
		cp[e]--;
		cp[e ^ 1]++;
		cur = next;
	}
	return;
}
void add_edge(int u, int v, int cost, int cap, int id) {
	ct[cnt] = cost; cp[cnt] = cap; to[cnt] = u; eid[cnt] = id; pre[cnt] = head[u]; head[u] = cnt++;
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n,k; cin >> n >> k; vn = n;
	for(int i = 0; i < n;i++) {
		cin >> s[i] >> t[i] >> c[i];
		t[i] = s[i] + t[i];
		tver.push_back(s[i]);
		tver.push_back(t[i]);
	}
	sort(tver.begin(),tver.end());
	for(int i = 0; i < tver.size();i++) {
		if(!i || tver[i - 1] != tver[i]) ver.push_back(tver[i]);
	}
	for(int i = 0; i < ver.size(); ++i) {
		mp[ver[i]] = i;
	}
	for(int i = 0; i < n;i++) {
		int u = mp[s[i]] , v = mp[t[i]];
		s[i] = u, t[i] = v;
		add_edge(u,v,c[i],1,i);
		add_edge(v,u,-c[i],0,i);
	}
	for(int i = 1; i < ver.size(); ++i) {
		add_edge(i - 1, i, 0, k,n+i-1);
		add_edge(i, i - 1, 0, 0,n+i-1);
		s[n + i - 1] = i - 1;
		t[n + i - 1] = i;
	}
	for(int i = 0; i < k;++i) {
		do_mincost();
	}
	for(int i = 0; i < n;i++) {
		cout << (cp[i * 2] ^ 1) << ' ';
	}
	return 0;
}