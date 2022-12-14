//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
pair<int,int> x[N];
int pl[N];
int n;
int go(int v,int len,int dir) {
//	cout << "GO " << v << ' ' << len << ' ' << dir << '\n';
	int u = lower_bound(x,x+n,make_pair(x[v].first + len * dir,dir * (int)1e9)) - x;
	if(dir == 1) u--;
	if(u == v) return v;
	int dis = abs(x[u].first - x[v].first);
	len %= 2 * dis;
	u = lower_bound(x,x+n,make_pair(x[v].first + len * dir,dir * (int)1e9)) - x;
	if(dir == 1) u--;
	if(u == v) return v;
	return go(u,len - abs(x[u].first - x[v].first),dir * -1);
}
int main() {
	ios_base::sync_with_stdio(0);
	int m; cin >> n >> m;
	for(int i = 0; i < n;i++) {
		cin >> x[i].first;
		x[i].second = i;
	}
	sort(x,x+n);
	for(int i = 0; i < n;i++) pl[x[i].second] = i;
	while(m--) {
		int v,len; cin >> v >> len; --v; v = pl[v];
		int next = lower_bound(x,x + n,make_pair(x[v].first + len,(int)1e9)) - x; next--;
		int prev = lower_bound(x,x + n,make_pair(x[v].first - len,(int)-1e9)) - x;
	//	cout << next << ' ' << prev << endl;
		if(next == v && prev == v) {
			cout << x[v].second + 1 << '\n';
			continue;
		}
		int ans;
		if(next == v) ans = go(prev,len - x[v].first + x[prev].first,1);
		else ans = go(next,len + x[v].first - x[next].first,-1);
		cout << x[ans].second + 1 << '\n';
	}
}