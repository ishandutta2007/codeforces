#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;

	cin >> n;
	string s;

	cin >> s;
	int num = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i-1] == 'S' && s[i] == 'F') {
			num++;
		}
		else if (s[i] != s[i-1]) {
			num--;
		}
	}
	cout << (num > 0 ? "YES" : "NO") << endl;
	exit(0);
}