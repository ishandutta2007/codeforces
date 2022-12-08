#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	a--;
	b--;
	int pow = 0;
	int cur = 1;
	while (cur < n) {
		cur*=2;
		pow++;
	}
	int cp = 1;
	int cpow = 0;
	while (true) {
		cp *= 2;
		cpow++;
		if (a/cp == b/cp) break;
	}
	if (cpow == pow) {
		cout << "Final!" << endl;
	}
	else cout << cpow << endl;
	// cout << cpow << endl;
	cin >> n;
}