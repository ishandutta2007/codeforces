//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 9;
int h[Maxn],n,k,coin,sum[Maxn];
vector<int> al[Maxn];
void dfs(int v,int p = -1) {
	h[v] = (p + 1 ? h[p] + 1 : 0);
	for(int i = 0; i < al[v].size();i++) {
		int u = al[v][i];
		if(u - p) dfs(u,v);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> coin;
	k = min(k,n - 1);
	for(int i = 0; i < n-1;i++) {
		int u,v; cin >> u >> v; --u,--v;
		al[u].push_back(v);
		al[v].push_back(u);
	}
	dfs(0);
	sort(h,h+n);
	for(int i = 1; i <= n;i++) sum[i] = sum[i - 1] + h[i - 1];
	long long ans = 0;
	for(long long cur = 1; cur <= h[n-1];cur++) {
		long long p = upper_bound(h,h+n,cur) - h;
		p--;
		long long l = 1,r = p;
		if(cur * p - sum[p + 1] <= coin) r = 1;
		else
			while(l < r - 1) {
				long long mid = l + r >> 1;
				if(cur * (p - mid + 1) - sum[p + 1] + sum[mid] <= coin) r = mid;
				else l = mid;
			} 
		ans = max(ans,p - r + 1);
	}
	cout << min(ans,(long long)k) << '\n';
}