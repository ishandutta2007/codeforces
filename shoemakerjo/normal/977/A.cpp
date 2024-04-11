#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	while (k--) {
		if (n%10 == 0) n/=10;
		else n--;
	}
	cout << n << endl;
	cin >> n;
}