#include <bits/stdc++.h>

//http://codeforces.com/contest/810/problem/A

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;

main()
{
	int n, k;
	cin >> n >> k;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
	}
	for (int a = 0; ; a++) {
		if (round((sum+a*k)/double(n+a)) >= k) {
			cout << a << endl;
			break;
		}
	}
	exit(0);
}