#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {

		int n;
		cin >> n;
		vector<int>a(n);
		vector<int>b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		for (int i = 0; i < n; i++) {
			cout << b[i] << " ";
		}
	}
	return 0;
}