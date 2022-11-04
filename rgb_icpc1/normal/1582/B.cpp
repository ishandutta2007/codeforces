#include <bits/stdc++.h>

using namespace std;

const int MX = 65;

int Tc, N;
int a[MX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		cin >> N;
		int x = 0 , y = 0;
		for(int i = 0 ; i < N ; i ++) {
			cin >> a[i];
			if(a[i] == 0) x ++;
			else if(a[i] == 1) y ++;
		}
		cout << (1LL << x) * y << endl;
	}

	return 0;

}