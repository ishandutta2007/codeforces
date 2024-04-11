#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int best = 1000000;

	// do b "before", then one or zero copies; then some after
	for (int b = 0; b <= n; b++) {
		// zero copies:
		best = min(best, b+(n-b)); // n
		// one copy
		string t = s.substr(0, b);
		t = t+t;
		if (2*b <= n && s.substr(0, 2*b) == t) {
			best = min(best, b+1+(n-2*b));
		}
	}
	cout << best << endl;
	exit(0);
}