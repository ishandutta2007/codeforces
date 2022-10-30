#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	cin >> t;
	for(cl=0; cl<t; cl++) {
		cin >> n;
		vector<int> a;
		for(i=0; i<n; i++) {
			cin >> in;
			a.push_back(in);
		}
		sort(a.begin(), a.end());
		cout << a[n-2]+a[n-1] << endl;
	}
}