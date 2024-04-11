#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	size_t sol = 0;
	for (int i=0; i<n; i++) {
		for (int j=i; j<=n; j++) {
			string p(s.begin()+i, s.begin()+j);
			string q = p;
			reverse(q.begin(), q.end());
			if (p != q)
				sol = max(sol, p.size());
		}
	}
	cout << sol;
}