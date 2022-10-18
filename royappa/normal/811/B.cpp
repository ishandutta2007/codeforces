#include <bits/stdc++.h>

//http://codeforces.com/contest/811/problem/B

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;

main()
{
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		int orank = x-l, nrank = 0;
		for (int j = l; j <= r; j++) {
			if (p[j-1] < p[x-1]) nrank++;
		}
		cout << (orank == nrank ? "Yes" : "No") << endl;
	}
	exit(0);
}