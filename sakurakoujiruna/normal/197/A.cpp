#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int a, b, r; cin >> a >> b >> r;
	if(a < 2 * r || b < 2 * r)
		cout << "Second\n";
	else
		cout << "First\n";
	return 0;
}