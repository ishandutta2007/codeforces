#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

// vector<pair<

const int maxn = 100010;

int nums[maxn];

int main() {
	
	int n;
	cin >> n;
	int sum = 0;
	int cur;
	for (int i = 1; i <= n; i++) {
		cin >> cur;
		nums[i] = cur;
		sum = sum^cur;
	}
	if (sum != 0 && n % 2 == 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	int turns = ((n-1)/2) * 2;
	cout << turns << endl;
	for (int i = 2; i < n; i+=2) {
		cout << 1 << " " << i << " " << i+1 << endl;
	}
	for (int i = 2; i < n; i+=2) {
		cout << 1 << " " << i << " " << i+1 << endl;
	}
}