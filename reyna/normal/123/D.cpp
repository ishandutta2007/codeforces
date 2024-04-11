//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N = 1e5 + 9;
const ll base = 37;
ll pw[N];
int sa[N];
int par[N],sz[N];
ll h[N];
char s[N];
pair<int,int> sr[N];
int n;
ll get_hash(int l,int r) {
	if(!l) return h[r];
	ll res = h[r] - (h[l - 1] * pw[r - l + 1]);
	return res;
}
int get_lcp(int x,int y) {
	int cur = 0;
	for(int b = 17; ~b; --b) {
		cur += 1 << b;
		if(cur > (n - x) || cur > (n - y) || get_hash(x,x+cur-1) != get_hash(y,y+cur-1)) cur -= 1 << b;
	}
	return cur;
}
bool cmp(int x,int y) {
	int lcp = get_lcp(x,y);
	if(lcp == n - x) return 1;
	if(lcp == n - y) return 0;
	return s[x + lcp] < s[y + lcp];
}
int find(int v) {
	if(par[v] != v) return par[v] = find(par[v]);
	return v;
}
void unite(int u,int v) {
	u = find(u),v = find(v);
	if(u == v) return;
	par[u] = v;
	sz[v] += sz[u];
	return;
}
main() {
	scanf("%s",s);
	n = strlen(s);
	for(int i = 0; i < n; ++i) pw[i] = ((i ? (pw[i-1] * base) : 1));
	for(int i = 0; i < n; ++i) h[i] = ((i ? h[i-1] * base : 0) + s[i]);
	for(int i = 0; i < n; ++i) sa[i] = i,par[i] = i,sz[i]++;
	sort(sa,sa+n,cmp);
	ll ans = 0;
	ll res = ((ll)n * (n + 1)) / 2;
	for(int i = 0; i < n - 1; ++i) sr[i] = {get_lcp(sa[i],sa[i+1]),i};
//	for(int i = 0; i < n; ++i) {
//		cout << sa[i] << '\n';
//	}
	sort(sr,sr+n - 1);
	reverse(sr,sr+n - 1);
	int last = sr[0].first + 1;
	for(int i = 0; i < n;++i) {
		if(i == n-1) break;
		int k = sr[i].second;
		if(sr[i].first == 0) break;
		while(last != sr[i].first) res += ans,last--;
	//	cout << sr[i].first << ' ' << k << " :D " << endl;
		int u = find(k),v = find(k + 1);
		ans += sz[u] * 1LL * sz[v];
		unite(u,v);
	//	cout << ans << ' ' << sz[v] << endl; 
	}
	while(last--) res += ans;
	cout << res << endl;
	return 0;
}