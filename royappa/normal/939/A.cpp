#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		int j = v[i];
		int k = v[j];
		if (v[k] == i) {
			cout << "YES" << endl;
			exit(0);
		}
	}
	cout << "NO" << endl;
	exit(0);
}