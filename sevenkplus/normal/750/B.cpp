#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

void end() {
	puts ("NO");
	exit(0);
}

int main() {
	int nw = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		int t; string s;
		cin >> t >> s;
		if (nw == 0 && s[0] != 'S') end();
		if (nw == 20000 && s[0] != 'N') end();
		if (s[0] == 'N') nw -= t; else
		if (s[0] == 'S') nw += t;
		if (nw < 0 || nw > 20000) end();
	}
	if (nw != 0) end();
	puts ("YES");
	return 0;
}