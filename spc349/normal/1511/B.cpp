#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while (T--) {
		int a, b, c; cin >> a >> b >> c; a--, b--, c--;
		int A = 1, B = 1, C = 1;
		while (a--) A *= 10; while (b--) B *= 10; while (c--) C *= 10;
		B += C;
		cout << A << " " << B << endl; 
	}
	return 0;
}