#include <bits/stdc++.h>
using namespace std;

const int N = 1e5L + 11;

#define pb push_back
vector <pair <int, int>> v[2];
int suf[N];
vector <int> sp[N];

int solve(vector <pair <int, int>> v, int C) {
	fill(suf, suf + N, -1);
	for(int i = 0; i < N; i ++)
		sp[i].clear();
	
	sort(v.begin(), v.end());
	for(auto i : v) {
		sp[i.first].pb(i.second);
		suf[i.first] = max(suf[i.first], i.second);
	}
	for(int i = 1; i < N; i ++)
		suf[i] = max(suf[i], suf[i - 1]);
	int ans = 0, n = v.size();
	for(int i = 0; i < n; i ++) {
		//int t = C - v[i].first;
		int t = min(v[i].first - 1, C - v[i].first);
		if(t < v[i].first && t >= 0 && ~suf[t])
			ans = max(ans, suf[t] + v[i].second);
	}
	for(int i = 0; i < N && 2 * i <= C; i ++) if(sp[i].size() >= 2) {
		sort(sp[i].begin(), sp[i].end(), greater<int>());
		ans = max(ans, sp[i][0] + sp[i][1]);
	}
	
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	int n, C, D; cin >> n >> C >> D;
	int mc = -1, md = -1;
	for(int i = 0; i < n; i ++) {
		int b, p; char c;
		cin >> b >> p >> c;
		if(c == 'C') v[0].pb({p, b});
		else v[1].pb({p, b});
		
		if(c == 'C' && p <= C)
			mc = max(mc, b);
		if(c == 'D' && p <= D)
			md = max(md, b);
	}
	int ans = max(solve(v[0], C), solve(v[1], D));
	if(~mc && ~md) ans = max(mc + md, ans);
	cout << ans << '\n';
}