#include<bits/stdc++.h>

using namespace std;

int main(){
	int x, y, p, q;
	cin >> x >> y >> p >> q;
	int l = p - 1, r = p + 1;
	int u = q + 1, d = q - 1;
	l = min(x, l);
	r = max(x, r);
	u = max(y, u);
	d = min(y, d);
	cout << (r - l + u - d) * 2 << endl;
	return 0;
}