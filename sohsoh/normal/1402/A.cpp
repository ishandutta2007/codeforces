#include <bits/stdc++.h>
using namespace std;
int main() {
	long long L, R;
	cin >> L >> R;
	cout << (1ll << __lg(R ^ L) + 1) - 2 + (((R ^ L) >> (__builtin_ctz(R ^ L))) & 1) << endl;
	return 0;
}