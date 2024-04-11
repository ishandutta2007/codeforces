#include <bits/stdc++.h>

//http://codeforces.com/contest/672/problem/A

using namespace std;


typedef long long LL;

typedef pair<int,int> pi;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n > 26)
	{
		cout << -1 << endl;
	}
	else
	{
		set<char> sc(s.begin(), s.end());
		cout << n-sc.size() << endl;
	}
	exit(0);
}