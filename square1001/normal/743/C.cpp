#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	if(n >= 2) cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << endl;
	else cout << -1 << endl;
	return 0;
}