#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n, k;
	cin >> n >> k;
	int b = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (k%x == 0) {
			b = max(b, x);
		}
	}
	cout << (k/b) << endl;
	exit(0);
}