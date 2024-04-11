#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t --) {
		int x, y; cin >> x >> y;
		string s; cin >> s;
		int L=0,R=0,U=0,D=0;
		for (int i = 0; s[i]; i ++) {
			if(s[i]=='L') ++L;
			if(s[i]=='R') ++R;
			if(s[i]=='U') ++U;
			if(s[i]=='D') ++D;
		}
		bool ok = 1;
		if (x < 0 && abs(x) > L) ok = 0;
		if (x > 0 && abs(x) > R) ok = 0;
		if (y < 0 && abs(y) > D) ok = 0;
		if (y > 0 && abs(y) > U) ok = 0;
		cout << (ok?"YES":"NO") << endl;
	}
}