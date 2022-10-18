#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n, m;
	cin >> n >> m;
	int r = 0;
	int mask = 0;
	for (int b = 0; b < n; b++) {
		mask = 2*mask+1;
		if (2*mask+1 > 1000000000) {
			break;
		}
	}
	cout << (m&mask) << endl;
	exit(0);
}