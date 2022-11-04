#include <bits/stdc++.h>

using namespace std;

const int MX = 500005;

int Tc, N;



int main() {
#ifndef ONLINE_JUDGE
	freopen("I", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		cin >> N;
		int k = sqrt(N);
		int m = k * k, r, c;
		if(m == N) r = k, c = 1;
		else if(N - m <= k){
			c = k + 1;
			r = (N - m);
		}
		else {
			c = k + 2 - (N - m - k);
			r = k + 1;
		}
		cout << r << " " << c << "\n";
			
	}
	return 0;

}