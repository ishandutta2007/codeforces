#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	string s1 = s;
	reverse(s1.begin(), s1.end());
	cout << s << s1 << endl;
}