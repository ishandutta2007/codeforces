#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int negs = 0;
	int pos = 0;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (cur < 0) negs++;
		else pos++;
		cin >> cur;
	}
	if (negs <= 1 || pos <= 1) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	cin >> n;
}