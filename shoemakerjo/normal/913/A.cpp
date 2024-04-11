#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	bool less = false;
	int cur = 1;
	for (int i = 1; i <= n; i++) {
		cur = cur*2;
		if (m < cur) {
			less = true;
			break;
		}
	}
	if (less) cout << m << endl;
	else {
		cout << m%cur << endl;
	}
	cin >> n;
}