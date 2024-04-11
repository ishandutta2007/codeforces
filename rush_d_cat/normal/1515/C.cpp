#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t; cin >> t;
	while (t --) {
		int n, m, x; 
		cin >> n >> m >> x;
		vector<int> h(n);
		cout << "YES" << endl;
		set< pair<int,int> > st;
		for (int i = 1; i <= m; i ++) st.insert({0, i});
		for (int i = 0; i < n; i ++) {
			cin >> h[i];
			auto it = st.begin();
			pair<int,int> b = (*it);
			st.erase(b);
			b.first += h[i];
			cout << b.second << " \n"[i==n-1];
			st.insert(b);
		}
	}
}