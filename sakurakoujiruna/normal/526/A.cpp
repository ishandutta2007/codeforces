#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	bool f = false;
	for(int i = 0; i < n; i ++) {
		for(int d = 1; d < n; d ++) {
			int cnt = 0;
			for(int j = i; j < n; j += d) if(cnt < 5) {
				if(s[j] == '*') cnt ++;
				else cnt = -233;
			}
			if(cnt == 5) f = true;
		}
	}
	cout << (f ? "yes" : "no") << '\n';
	return 0;
}