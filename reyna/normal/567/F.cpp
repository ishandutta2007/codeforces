//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
vector<pair<int,string> > q[N];
int dp[N][N];
int ch(int l,int r,int x,int y) {
	for(int i = 0; i < q[x].size(); ++i) {
		int pl = q[x][i].first;
		string s = q[x][i].second;
		if(s == "=" && (pl != y && pl != x)) return 0;
		if(s == "<=" && (pl < l || pl > r)) return 0;
		if(s == ">=" && (l <= pl && pl <= r && pl != x && pl != y)) return 0;
		if(s == "<" && (pl < l || pl > r || pl == x || pl == y)) return 0;
		if(s == ">" && (l <= pl && pl <= r)) return 0;
	}
	return 1;
}
int check(int l,int r,int x,int y) {
	if(!ch(l,r,x,y)) return 0;
	if(!ch(l,r,y,x)) return 0;
	return 1;
}
main() {
	int n,k; cin >> n >> k;
	for(int i = 0; i < k; ++i) {
		int u,v; string s;
		cin >> u >> s >> v;
		--u,--v;
		q[u].push_back({v,s});
	}
	for(int i = 0; i < 2 * n - 1; ++i) {
		dp[i][i+1] = check(i,i+1,i,i+1);
	}
	for(int len = 3; len < 2 * n; len += 2) {
		for(int l = 0; l < 2 * n - len; ++l) {
			int r = l + len;
			if(check(l,r,l,l+1)) dp[l][r] += dp[l + 2][r];
			if(check(l,r,l,r)) dp[l][r] += dp[l+1][r-1];
			if(check(l,r,r-1,r)) dp[l][r] += dp[l][r-2];
		}
	}
	cout << dp[0][2 * n - 1] << endl;
	return 0;
}