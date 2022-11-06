#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

#define INF 1e9
#define PI 3.1415927

long long gcd(long long m, long long n) {
	return ((n == 0) ? m : gcd(n, m%n));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	cout << (n - 1) / 2;

	return 0;
}