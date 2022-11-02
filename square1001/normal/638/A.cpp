#include <bits/stdc++.h>
using namespace std;
int n, a;
int main() {
	cin >> n >> a;
	if(a % 2 == 1) cout << a / 2 + 1 << endl;
	else cout << (n - a) / 2 + 1 << endl;
	return 0;
}