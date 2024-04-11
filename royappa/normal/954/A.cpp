#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int c = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i-1]) {
			c++;
			i++;
		}
	}
	cout << n-c << endl;
	exit(0);
}