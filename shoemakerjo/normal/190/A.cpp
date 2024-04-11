#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	if (n == 0 && m > 0) {
		cout << "Impossible" << endl;
	}
	else {
		int low = n+m;
		low -= min(n, m);
		int high = n+m;
		if (m > 0) high--;
		cout << low << " " << high << endl;
	}
	cin >> n;

}