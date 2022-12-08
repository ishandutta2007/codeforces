#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	int n;
	cin >> n;
	ll small = 0;
	ll heights[n+1];
	heights[0] = 0;
	ll cur = 0;
	for (int i = 1; i <= n; i++) {
		cin >> heights[i];
		cur += heights[i-1]-heights[i];
		small = min(small, cur);
	}
	cout << 0-small << endl;
	// cin >> n;

}