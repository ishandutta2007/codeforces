//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
typedef long long ll;
#define int long long
ll dp[N];
ll t[N],ch[N];
ll cost[N];
ll ql[N],qr[N],p[N];
int n;
vector <pair<ll,ll> > do_query[N];
void prop(int v,int l,int r) {
	ch[l] += ch[v],ch[r] += ch[v];
	t[l] += ch[v],t[r] += ch[v];
	ch[v] = 0;
	return;
}
void update(int i,int j,int x,int v = 1,int b = 0,int e = n) {
	if(i > e || b > j) return;
	if(i <= b && e <= j) {
		ch[v] += x;
		t[v] += x;
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	prop(v,l,r);
	update(i,j,x,l,b,mid);
	update(i,j,x,r,mid+1,e);
	t[v] = max(t[l],t[r]);
	return;
}
ll query(int i,int j,int v = 1,int b = 0,int e = n) {
	if(i > e || b > j) return -1e18;
	if(i <= b && e <= j) return t[v];
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	prop(v,l,r);
	return max(query(i,j,l,b,mid),query(i,j,r,mid+1,e));
}
main() {
	ios_base::sync_with_stdio(0);
	int m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> cost[i];
	for(int i = 0; i < m; i++) {
		cin >> ql[i] >> qr[i] >> p[i];
		do_query[qr[i]].push_back({ql[i],p[i]});
	}
	for(int i = 1; i <= n ; i++) {
		dp[i] = max(dp[i],dp[i-1]);
		update(0,i - 1,-cost[i - 1]);
		for(int j = 0; j < do_query[i].size(); j++) {
			int l = do_query[i][j].first,pr = do_query[i][j].second;
			update(0,l - 1,pr);
		}
		dp[i] = max(dp[i],query(0,i - 1));
		//	cout << dp[i] << '\n';
		update(i,i,dp[i]);
	}
	cout << dp[n] << '\n';
	return 0;
}