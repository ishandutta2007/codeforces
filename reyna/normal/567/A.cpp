//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
pair<int,int> x[N];
int mn[N],mx[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 0; i < n; ++i) cin >> x[i].first,x[i].second = i;
	sort(x,x+n);
	for(int i = 0; i < n; ++i) {
		int pl = x[i].first,id = x[i].second;
		mn[id] = 2e9 + 2;
		if(i) mn[id] = min(mn[id],abs(pl -x[i-1].first));
		if(i != n-1) mn[id] = min(mn[id],abs(pl - x[i+1].first));
		mx[id] = max(mx[id],abs(pl - x[0].first));
		mx[id] = max(mx[id],abs(pl - x[n-1].first));
	}
	for(int i = 0; i < n; ++i) {
		cout << mn[i] << ' ' << mx[i] << '\n';
	}
	return 0;
}