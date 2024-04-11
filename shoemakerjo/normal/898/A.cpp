#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 10 <= 5) {
		cout << n-(n%10) << endl;
	}
	else {
		cout << n-(n%10) + 10 << endl;
	}
	cin >> n;
}