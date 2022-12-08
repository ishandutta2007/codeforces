#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int a, b;

	int res = 1;

	int pa = 0, pb = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		int st = max(pa, pb);
		int en = min(a, b);

		if (en >= st) {
			res += en-st+1;

			if (pa == pb) res--;
		}
		
		pa = a;
		pb = b;

		// cout << "    " << i << " " << res << endl;
	}
	cout << res << endl;

}