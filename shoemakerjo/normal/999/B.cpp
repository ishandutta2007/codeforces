#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	string s; cin >> s;
	for(int a = 1; a <= n; a++) {
		if (n%a) continue;
		reverse(s.begin(), s.begin()+a);	
	}
	cout << s << '\n';
}