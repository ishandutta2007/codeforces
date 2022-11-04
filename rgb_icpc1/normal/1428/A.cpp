#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	for (cin >> T; T --;) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		int dx = abs(ex - sx), dy = abs(ey - sy);
		int rlt;
		if (dx == 0 && dy == 0) rlt = 0;
		else if (dx == 0) rlt = dy;
		else if (dy == 0) rlt = dx;
		else rlt = dx + 2 + dy;
		cout << rlt << endl;
	}
}