#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int n, m; cin >> n >> m;
	set <string> st;
	for(int i = 0; i < n; i ++) {
		string s; cin >> s;
		st.insert(s);
	}
	int both = 0;
	for(int j = 0; j < m; j ++) {
		string s; cin >> s;
		if(st.count(s))
			both ++;
	}
	n -= both; m -= both;
	both = both % 2;
	if(n + both > m)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}