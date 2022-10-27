#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int gcd(int x, int y) {
	return y==0?x:gcd(y,x%y);
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		int n; cin >> n;
		vector<int> a(n), nex(n);
		for (int i = 0; i < n; i ++) {
			cin >> a[i]; nex[i] = (i+1) % n;
		}
		
		set<int> st;
		for (int i = 0; i < n; i ++) {
			if (gcd(a[i], a[(i+1)%n]) == 1) st.insert(i);
		} 
		int now = 0;
		vector<int> ans;
		while (st.size()) {
			auto it = st.lower_bound(now);			
			int idx = -1;
			if (it == st.end()) {
				idx = (*st.begin());
			} else {
				idx = (*it);
			}
			int pos1 = idx;
			int pos2 = nex[idx];
			ans.push_back(pos2 + 1);
			if (st.find(pos2) != st.end()) st.erase(pos2);
			nex[pos1] = nex[pos2];
			if (gcd(a[pos1], a[nex[pos1]]) != 1) st.erase(pos1);
			now = nex[pos1];
		}

		cout << ans.size() << " ";
		for (auto x: ans) cout << x << " ";
		cout << endl;
	}	
}