#include <bits/stdc++.h>
using namespace std;
long long t, s, x;
int main() {
	cin >> t >> s >> x;
	cout << ((x == t || (x >= t + s && (x - t - s) % s <= 1)) ? "YES" : "NO") << endl;
	return 0;
}