#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main () {
	int t;
	cin >> t;
	while (t --) {
		
		cin >> a >> b >> c;
		cout << max (0, max(b, c) + 1 - a) << ' ';
		cout << max (0, max(a, c) + 1 - b) << ' ';
		cout << max (0, max(b, a) + 1 - c) << endl;
		
	}
	
}