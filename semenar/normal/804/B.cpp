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
#define P 1000000007

long long gcd(long long m, long long n) {
	return ((n == 0) ? m : gcd(n, m%n));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	
	long long b = 0, ans = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == 'b') b++;
		else {
			ans = (ans + b) % P;
			b = (b * 2) % P;
		}
	}

	cout << ans;

	return 0;
}