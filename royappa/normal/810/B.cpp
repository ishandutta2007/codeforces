#include <bits/stdc++.h>

//http://codeforces.com/contest/810/problem/B

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;

main()
{
	int n, f;
	cin >> n >> f;
	vector<LL> sale(n);
	LL tot = 0;
	for (int i = 0; i < n; i++) {
		int k, l;
		cin >> k >> l;
		tot += min(l,k);
		sale[i] = max(0, min(l,2*k)-k);
	}
	sort(sale.rbegin(), sale.rend());
	tot += accumulate(sale.begin(), sale.begin()+f, 0LL);
	cout << tot << endl;
	exit(0);
}