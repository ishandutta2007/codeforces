#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n %2 != 0) {
		cout << 0 << endl;
		return 0;
	}
	int num = n/2;
	if (num * 2 == n) num--;
	if (num%2==1) num--;
	cout << num/2 << endl;
	cin >> n;
}