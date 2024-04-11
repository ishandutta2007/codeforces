#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	cout << 100003 << " " << 100003 << endl;
	for (int i = 1; i < n-1; i++) {
		cout << i << " " << i+1 << " " << 1 << endl;
	}
	cout << n-1 << " " << n << " " << 100003-(n-2) << endl;
	int numneed = m-(n-1);
	int st = 1;
	int en = 3;
	for (int j = 0; j < numneed; j++) {
		cout << st << " " << en << " " << 1000000000 << endl;
		en++;
		if (en > n) {
			st++;
			en = st+2;
		}
	}
	cin >> n;
}