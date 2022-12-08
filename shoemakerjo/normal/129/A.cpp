#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	int odd = 0;
	int even = 0;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		sum+=cur;
		if (cur%2==0) even++;
		else odd++;
	}
	if (sum%2==0) cout << even << endl;
	else cout << odd << endl;
}