#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
	ios :: sync_with_stdio(false);
	ull a, b; cin >> a >> b;
	ull h = 0;
	for(int i = 0; i < 64; i ++)
		if(((a ^ b) >> i) & 1)
			h = (1ULL << i);
	if(h == 0)
		cout << 0 << '\n';
	else
		cout << h * 2 - 1 << '\n';
	return 0;
}