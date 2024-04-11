#include <bits/stdc++.h>

using namespace std;
typedef long long LL;



int main()
{
	LL n, m;
	cin >> n >> m;
	LL res = 0;
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < m; y++) {
			if (x > n || y > n) continue;
			if ((x*x+y*y)%m != 0) continue;
			LL numx = 1+(n-x)/m;
			LL numy = 1+(n-y)/m;
			if (x == 0) numx--;
			if (y == 0) numy--;
			//if (m == 5) cout << x << "," << y << ": " << numx << "," << numy << endl;
			res += numx*numy;
		}
	}
	cout << res << endl;
	exit(0);
}