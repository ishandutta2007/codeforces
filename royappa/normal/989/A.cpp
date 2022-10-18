#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	bool found = false;
	for (int i = 0; i < n-1; i++) {
		if (i-1 >= 0 && (s[i] == '.' || s[i-1] == '.' || s[i+1] == '.')) continue;
		if (i-1 >= 0 && s[i] != s[i-1] && s[i] != s[i+1] && s[i-1] != s[i+1]) {
			found = true;
		}
	}
	cout << (found ? "Yes" : "No") << endl;
	exit(0);
}