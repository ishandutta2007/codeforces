#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	string s = "EASY";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x) s = "HARD";
	}
	cout << s << endl;
	exit(0);
}