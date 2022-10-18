#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;

// Algorithm

main()
{
	string s;
	int n, k;

	cin >> n >> k;
	cin >> s;

	map<char,int> last;
	map<char,int> open;

	for (int p = n-1; p >= 0; p--) {
		if (last.count(s[p]) == 0) {
			last[s[p]] = p;
			open[s[p]] = 0;
		}
	}

	int maxOpen = 0, numOpen = 0;
	for (int i = 0; i < n; i++) {
		if (!open[s[i]]) {
			open[s[i]] = 1;
			numOpen++;
		}
		maxOpen = max(maxOpen, numOpen);
		if (i == last[s[i]]) {
			open[s[i]] = 0;
			numOpen--;
		}
	}
	cout << ((maxOpen > k) ? "YES" : "NO") << endl;

	exit(0);
}