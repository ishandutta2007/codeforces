#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int A,B,C,D;

int main() {
	cin >> A >> B >> C >> D;
	int xmax = B - A;
	int ymax = C - B;
	int zmax = D - C;
	LL ans = 0;
	for (int i = 0; i <= xmax + ymax; i ++) {
		int z = i - (C - A - B) - 1;
	
		if (z >= 0) {
			LL c1 = 0;
			if (i <= min(xmax, ymax)) c1 = i + 1;
			else if (i >= max(xmax, ymax)) c1 = (xmax + ymax) - i + 1;
			else c1 = min(xmax, ymax) + 1;

			LL c2 = min(z, zmax) + 1;
			ans += c1 * c2;
		}  
	}
	cout << ans << endl;
}