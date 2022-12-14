//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
set<int> st;
int ans[N],mark[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n,k,a; cin >> n >> k >> a;
	int m; cin >> m;
	st.insert(0);
	st.insert(n+1);
	for(int i = a; i < n; i += a + 1) {
		ans[i]++;
	}
	for(int i = 0; i < N; ++i) if(i) ans[i] += ans[i-1];
	int res = ans[n];
	for(int q = 0; q < m; ++q) {
		int x; cin >> x;
		if(mark[x]) continue;
		mark[x] = 1;
		auto it1 = st.lower_bound(x);
		auto it2 = it1;
		it2--;
		int sz = *it1 - *it2 - 1;
		res -= ans[sz];
		res += ans[(*it1) - x - 1];
		res += ans[x - (*it2) - 1];
		if(res < k) {
			cout << q + 1 << endl;
			return 0;
		}
		st.insert(x);
	}
	cout << -1 << endl;
	return 0;
}