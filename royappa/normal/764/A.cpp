#include <bits/stdc++.h>

//http://codeforces.com/contest/761/problem/0

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

int main()
{
	int n, m, z;
	cin >> n >> m >> z;
	int g = gcd(n, m);
	int l = (n*m)/g;
	cout << z / l << endl;
	exit(0);
}