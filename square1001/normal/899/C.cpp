#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int la[] = { 1, 1, 2, 3 };
int lb[] = { 0, 2, 3, 0 };
int n;
int main() {
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (i % 4 == la[n % 4] || i % 4 == lb[n % 4]) v.push_back(i);
	}
	cout << (n % 4 == 0 || n % 4 == 3 ? 0 : 1) << endl;
	cout << v.size();
	for (int i = 0; i < v.size(); i++) cout << ' ' << v[i];
	return 0;
}