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
	long long n, m,k;
	cin >> n >> m >> k;
	if (2 * n * m % k != 0) {
		cout << "NO";
		return 0;
	}
	long long z = 2 * n * m / k;
	int n1 = 0;
	int a = 2 * n;
	int b = k;
	int c = m;
	int y = 0;
	while (b > 0) {
		y = b;
		b = a % b;
		a = y;
	}
	b = k;
	while (b > 0) {
		y = b;
		b = c % b;
		c = y;
	}
	
	if (a != 1) {
		cout << "YES" << '\n';
		cout << 2 * n / a << " " << 0 << '\n';
		cout << 0 << " " << 0 << '\n';
		cout << 0 << " " << m * a / k;
	}
	else {
		cout << "YES" << '\n';
		cout << n << " " << 0 << '\n';
		cout << 0 << " " << 0 << '\n';
		cout << 0 << " " << m * 2 / k;
	}
	
	
	return 0;
}