#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int te = 0;
	int ts = abs(x-y) * t1;
	te += t3*3;
	te += abs(x-z) * t2;
	te += abs(x-y) * t2;
	// cout << te << " " << ts << endl;

	if (te <= ts) cout << "YES" << endl;
	else cout << "NO" << endl;

	
}