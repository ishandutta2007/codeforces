#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	
	if (k%2 == 0) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << ".";
		}
		cout << endl;
		cout << ".";
		for (int i = 0; i < k/2; i++) {
			cout << "#";
		}
		for (int i = 0; i < n-1-k/2; i++) {
			cout << ".";
		}
		cout << endl;
		cout << ".";
		for (int i = 0; i < k/2; i++) {
			cout << "#";
		}
		for (int i = 0; i < n-1-k/2; i++) {
			cout << ".";
		}
		cout << endl;
		for (int i = 0; i < n; i++) cout << ".";
		cout << endl;
	}
	else if (k <= n-2) { //k is odd for sure
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << ".";
		}
		cout << endl;
		int nv = (n-k)/2;
		for (int i = 0; i < nv; i++) {
			cout << ".";
		}
		for (int i = 0; i < k; i++) {
			cout << "#";

		}
		for (int i = 0; i < nv; i++) {
			cout << ".";
		}
		cout << endl;

		for (int i = 0; i < n; i++) {
			cout << ".";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << ".";
		}
		cout << endl;
	}
	else if (k %2 == 1 && k >= 5) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << ".";
		}
		cout << endl;
		cout << ".";
		for (int i = 0; i < k/2+1; i++) {
			if (i != 1) cout << "#";
			else cout << ".";
		}
		for (int i = 0; i < n-2-k/2; i++) {
			cout << ".";
		}
		cout << endl;
		cout << ".";
		for (int i = 0; i < k/2+1; i++) {
			cout << "#";
		}
		for (int i = 0; i < n-2-k/2; i++) {
			cout << ".";
		}
		cout << endl;
		for (int i = 0; i < n; i++) cout << ".";
		cout << endl;
	}
	else {
		cout << "NO" << endl;

	}
	cin >> n;
}