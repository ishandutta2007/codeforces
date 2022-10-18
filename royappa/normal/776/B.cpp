#include <bits/stdc++.h>

//http://codeforces.com/contest/776/problem/0

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n+2, 1);

	for (int x = 2; x*x <= n+1; x++) {
		if (v[x]) {
			for (int z = x+x; z <= n+1; z += x) {
				v[z] = 0;
			}
		}
	}
	// every 1 is prime, every 0 is composite
	// every prime can be the same color, 1
	// every composite must be a different color, 2
	set<int> s;
	for (int i = 2; i <= n+1; i++) {
		if (v[i] == 0) v[i] = 2;
		s.insert(v[i]);
	}
	cout << s.size() << endl;
	for (int i = 2; i <= n+1; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	exit(0);
}