#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		if (i % 2 == 0) {
			s += "I hate that ";
		}
		else {
			s += "I love that ";
		} 
	}

	if (n % 2 == 0) {
		s += "I love it";
	}
	else {
		s += "I hate it";	
	}
	cout << s;
}