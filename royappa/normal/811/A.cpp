#include <bits/stdc++.h>

//http://codeforces.com/contest/811/problem/0

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;

main()
{
	LL v[2];
	cin >> v[0] >> v[1];
	int turn = 0;
	for (LL t = 1; ; t++) {
		if (v[turn] < t) {
			cout << ((turn == 0) ? "Vladik" : "Valera") << endl;
			break;
		}
		v[turn] -= t;
		turn = 1-turn;
	}
	exit(0);
}