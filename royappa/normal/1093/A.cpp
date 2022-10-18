#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x%2 == 0) {
			cout << x/2 << endl;
		}
		else {
			cout << 1+(x-3)/2 << endl;
		}
	}
	exit(0);
}