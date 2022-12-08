#include <bits/stdc++.h>

using namespace std;

bool check(int u) {
	
	int sum = 0;
	while (u > 0) {
		sum += u%10;
		u /= 10;
	}
	// cout << u << "   " << sum << endl;
	return sum == 10;
}

int main() {
	int k;
	cin >> k;
	int cur = 0;
	while (k > 0) {
		cur++;
		if (check(cur)) k--;
	}
	cout << cur << endl;
	cin >> k;
}