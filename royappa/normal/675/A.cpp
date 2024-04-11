#include <bits/stdc++.h>

//http://codeforces.com/contest/675/problem/A

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	LL a, b, c;
	cin >> a >> b >> c;
	// exists b = a+i*c for i >= 0 ?
	if (c == 0)
		cout << ((b == a) ? "YES" : "NO") << endl;
	else
		cout << (((b-a)%c || (b-a)/c < 0LL) ? "NO" : "YES") << endl;
	exit(0);
}