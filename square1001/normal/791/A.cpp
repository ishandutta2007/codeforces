#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
	cin >> a >> b;
	for(int i = 1; ; i++) {
		a *= 3, b *= 2;
		if(a > b) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}