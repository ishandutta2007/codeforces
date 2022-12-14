//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int Maxn = 1e5 + 9 , Mod = 1e9 + 7, lg = 21;
ll pw(ll a,ll b) { return b?(pw((a * a) % Mod, b >> 1) * (b & 1 ? a : 1)) % Mod : 1; }
ll gcd(ll a,ll b) { return (a >= b) ? (b?gcd(b,a%b):a) : gcd(b,a);}
int fort[Maxn],n,m,k;
int cnt[Maxn],vis[Maxn];
vector<int> al[Maxn];
vector<int> ans;
int Que[Maxn],bg,ed;
bool check(ld x) {
	bg = 0,ed = 0;
	memset(vis,0,sizeof vis);
	for(int v = 0; v < n;v++) {
		if(fort[v]) continue;
		cnt[v] = 0;
		for(int i = 0; i < al[v].size();i++) {
			cnt[v] += 1 - fort[al[v][i]];
		}
		if((ld)cnt[v] / al[v].size() < x) Que[ed++] = v, vis[v] = 1;
	}
	while(bg != ed) {
		int v = Que[bg++];
		for(int i = 0; i < al[v].size();i++) {
			int u = al[v][i];
			if(!fort[u] && !vis[u]) {
				cnt[u]--;
				if((((ld)cnt[u]) / al[u].size()) < x) Que[ed++] = u,vis[u] = 1;
			}
		}
	}
	int res = 0;
	for(int i = 0;i < n;i++) if(!fort[i] && !vis[i]) res++;
	if(res) {
		ans.clear();
		for(int i = 0; i < n;i++) if(!fort[i] && !vis[i]) ans.push_back(i+1);
		return 1;
	}
	return 0; 
}
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i = 0; i < k;i++) {
		int v; cin >> v; --v;
		fort[v] = 1;
	}
	for(int i = 0; i < m;i++) {
		int u,v; cin >> u >> v; --u,--v;
		al[u].push_back(v);
		al[v].push_back(u);
	}
	for(int i = 0; i < n;i++) {
		if(!fort[i] && al[i].size() == 0) {
			cout << 1 << '\n';
			cout << i + 1 << '\n';
			return 0;
		}
	}
	ld l = -2,r = 2;
	for(int i = 0; i < 300;i++) {
		ld mid = (l + r) / 2;
		if(check(mid)) {
			l = mid;
		}
		else r = mid;
	}
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size();i++) cout << ans[i] << ' ';
	return 0;
}