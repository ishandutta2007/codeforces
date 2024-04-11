#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 3e5 + 10;
int a[N];
vector<int> vec[N];
LL solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++) {
		scanf("%d", a + i);
	}
	set<pair<int, int>> st;
	for(int x, y; m --; ) {
		scanf("%d %d", &x, &y);
		st.insert({x, y});
		st.insert({y, x});
	}
	sort(a, a + n);
	vector<int> id;
	for(int i = n - 1, j; i >= 0; i = j) {
		for(j = i; j >= 0 && a[j] == a[i]; j --);
		vec[i - j].push_back(a[i]);
		id.push_back(i - j);
	}
	sort(id.begin(), id.end());
	id.resize(unique(id.begin(), id.end()) - id.begin());
	LL ans = 0;
	for(auto i : id) {
		for(auto j : id) {
			if(i <= j) {
				for(auto x : vec[i]) {
					for(auto y : vec[j]) {
						if(x != y && !st.count({x, y})) {
							ans = max(ans, 1ll * (x + y) * (i + j));
							break;
						}
					}
				}
			}
		}
	}
	for(auto r : id) {
		vec[r].clear();
	}
	return ans;
}
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		printf("%I64d\n", solve());
	}
	return 0;
}