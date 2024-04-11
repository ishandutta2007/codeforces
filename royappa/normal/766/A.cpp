#include <bits/stdc++.h>

//http://codeforces.com/contest/766/problem/A

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	string a, b;
	cin >> a >> b;
	if (a == b) {
		cout << -1 << endl;
	}
	else {
		cout << max((int)a.size(), (int)b.size()) << endl;
	}
	exit(0);
}