#include <bits/stdc++.h>

//http://codeforces.com/contest/776/problem/0

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;

int main()
{
	string a, b;

	cin >> a >> b;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << a << " " << b << endl;
		string c, d;
		cin >> c >> d;
		if (c == a) {
			a = b;
			b = d;
		}
		else {
			b = a;
			a = d;
		}
	}
	cout << a << " " << b << endl;
	exit(0);
}