#include <bits/stdc++.h>

//http://codeforces.com/contest/761/problem/0

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int v[200001];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		if (i < n/2) {
			cout << (((i&1) == 0) ? v[n-i-1] : v[i]);
		}
		else {
			cout << (((n-i-1)&1) == 0 ? v[n-i-1] : v[i]);
		}
		if (i != n-1) cout << " ";
	}
	cout << endl;
	exit(0);
}