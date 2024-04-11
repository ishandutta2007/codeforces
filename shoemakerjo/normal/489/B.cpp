#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n; 
	cin >> n;
	vector<int> boys;
	
	vector<int> girls;
	int cur = 0;
	int m;

	for (int i = 0; i < n; i++) {
		cin >> cur;
		boys.push_back(cur);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> cur;
		girls.push_back(cur);
	}

	sort(boys.begin(), boys.end());
	sort(girls.begin(), girls.end());
	
	bool taken[m];
	for (int i = 0; i < m; i++) taken[i] = false;

	int count = 0;
	

	for (int i = n-1; i >= 0; i--) {
		for (int j = m-1; j >= 0; j--) {
			if (abs(boys[i]-girls[j]) <= 1 && !taken[j]) {
				taken[j] = true;
				count++;
				break;
			}
		}
	}
	cout << count << endl;
	cin >> n;
}