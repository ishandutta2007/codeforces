#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, X;
		cin >> n >> X;
		vector<int> a(n);
		for(auto& y : a) cin >> y;
		set<int> st;
		int res = 0;
		for(int x : a) {
			st.insert(x);
			if ((*st.rbegin() - *st.begin()) > 2 * X) {
				res++;
				st.clear();
				st.insert(x);
			}
		}
		cout << res << '\n';
	}

}