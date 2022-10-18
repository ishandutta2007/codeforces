#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	map<int,int> best; // best[school i] = student j

	vector<int> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		best[s[i]] = 0;
	}
	for (int i = 0; i < n; i++) {
		best[s[i]] = max(best[s[i]], v[i]);
	}
	int res = 0;
	for (int j = 0; j < k; j++) {
		int x;
		cin >> x;
		x--;
		if (v[x] < best[s[x]]) res++;
	}
	cout << res << endl;
	exit(0);
}