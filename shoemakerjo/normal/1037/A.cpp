#include <bits/stdc++.h>

using namespace std;

int go(int val) {
	if (val == 1) return 1;
	int half = (val)/2;
	return 1 + go(half);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << go(n) << endl;
}