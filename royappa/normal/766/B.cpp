#include <bits/stdc++.h>

//http://codeforces.com/contest/766/problem/A

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	int n;
	cin >> n;
 	vector<LL> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i+2 < n; i++) {
		if (v[i]+v[i+1] > v[i+2]) {
			cout << "YES" << endl;
			exit(0);
		}
	}
	cout << "NO" << endl;
	exit(0);
}