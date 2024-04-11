#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++)
			cin >> a[i];
		string s;
		cin >> s;
	
		int b = count(s.begin(), s.end(), 'B');
		multiset<int> st;
		for (int i = 0; i < n; i ++)
			if (s[i] == 'B')
				st.insert(a[i]);
		
		bool ok = true;

		for (int i = 1; i <= b; i ++) {
			auto it = st.lower_bound(i);
			if (it == st.end())
				ok = false;
			else
				st.erase(it);
		}
		//printf("%d\n", ok);
		st.clear();
		for (int i = 0; i < n; i ++)
			if (s[i] == 'R') {
				//printf("! %d\n", a[i]);
				st.insert(a[i]);
			}
		
		for (int i = n; i >= b + 1; i --) {
			auto it = st.upper_bound(i);
			//printf("%d\n", *prev(it));
			if (it != st.begin()) {
				st.erase(prev(it));
			}  else {
				ok = false;
			}
		}
		cout << (ok?"YES":"NO") << "\n";
	}
}