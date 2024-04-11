#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll nums[n];
	ll su = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		su += nums[i];
	}
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		cur += nums[i];
		if (cur*2 >= su) {
			cout << i+1 << endl;
			break;
		}
	}
	cin >> n;
}