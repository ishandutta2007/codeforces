#include <bits/stdc++.h>

//http://codeforces.com/contest/688/problem/B

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	string n;
	cin >> n;
	string m = n;
	reverse(m.begin(), m.end());
	cout << n+m << endl;
	exit(0);
}