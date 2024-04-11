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
	int n;
	cin >> n;
	vector<long long>a(n);
	vector<long long>b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	long long c = 0;
	for (int i = 0; i < n; i++) {
		c = max(c, a[i] + b[i]);
	}
	cout << c;


	return 0;
	
}