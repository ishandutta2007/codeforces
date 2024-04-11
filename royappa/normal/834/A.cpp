#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;

// Algorithm

main()
{
	string s, t;

	cin >> s >> t;
	LL n;
	cin >> n;

	string d = "v<^>";

	LL p = (int)d.find(s[0]);

	LL q = (p+n)%4;

	int dir = 0;
	if (t == d.substr(q, 1))
		dir |= 1;

	q = (((p-n)%4)+4)%4;

	if (t == d.substr(q, 1))
		dir |= 2;

	if (dir == 1)
		cout << "cw";
	else if (dir == 2)
		cout << "ccw";
	else
		cout << "undefined";
	cout << endl;

	exit(0);
}