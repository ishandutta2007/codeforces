#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	int n;
	cin >> n;
	ll nums[n];
	ll goal = -1;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		
		cin >> nums[i];
		
		while (nums[i]%2 == 0) nums[i]/=2;
		while (nums[i]%3 == 0) nums[i]/=3;

		if (i == 0) goal = nums[i];
		else {
			if (nums[i] != goal) ok = false;
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	// cin >> n;


}