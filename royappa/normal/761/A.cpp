#include <bits/stdc++.h>

//http://codeforces.com/contest/761/problem/0

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	int a, b;
	cin >> a >> b;
	cout << (abs(a-b)<=1 && !(a==0&&b==0) ? "YES" : "NO") << endl;
	exit(0);
}