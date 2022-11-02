#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	if(n % 3 == 0) cout << 2 * (n / 3) << endl;
	else cout << 2 * (n / 3) + 1 << endl;
	return 0;
}