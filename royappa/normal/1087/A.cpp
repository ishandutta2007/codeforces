#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

string f(string s) {
	if (s.size() < 2) {
		return s;
	}
	int n = s.size();
	if (n%2 == 0) {
		string x = s.substr(n-1);
		return f(s.substr(0,n-1))+x;
	}
	else {
		string x = s.substr(0,1);
		return f(s.substr(1))+x;
	}
}
int main()
{
	string s;
	cin >> s;
	int n = s.size();

	cout << f(s) << endl;
	exit(0);
}