#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int h1, a1, c1, h2, a2;
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	vector<string> res;
	while (h2 > 0) {
		if (h1 > a2 || h2 <= a1) {
			res.push_back("STRIKE");
			h2 -= a1;
		}
		else {
			res.push_back("HEAL");
			h1 += c1;
		}
		h1 -= a2;
	}
	cout << res.size() << endl;
	for (auto x : res) {
		cout << x << endl;
	}
	exit(0);
}