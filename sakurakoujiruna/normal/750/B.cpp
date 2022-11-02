#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int t = 0;
	bool f = 1;
	while(n --) {
		int x; string s;
		cin >> x >> s;
		if(t == 0 && s[0] != 'S') f = 0;
		if(t == 20000 && s[0] != 'N') f = 0;
		if(s[0] == 'S') t += x;
		if(s[0] == 'N') t -= x;
		if(t < 0 || t > 20000) f = 0;
	}
	if(t != 0) f = 0;
	cout << (f ? "YES" : "NO") << '\n';
}