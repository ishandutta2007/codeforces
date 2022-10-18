#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	int L = 0, R = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < 0) L++; else R++;
	}
	if (L <= 1 || R <= 1) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	cout << endl;
	exit(0);
}