#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		v.push_back(cur);
	}
	sort(v.begin(), v.end());
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll mult = i+2;
		if (i == n-1) mult--;
		sum += mult*v[i];
	}
	cout << sum << endl;
	// cin >> n;
}