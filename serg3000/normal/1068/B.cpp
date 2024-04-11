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
	long long b;
	cin >> b;
	int ans = 0;
	for (int i = 1; i <= sqrt(b); i++) {
		if (i == sqrt(b) && b % i == 0) {
			ans++;
		}
		if (i != sqrt(b) && b % i == 0) {
			ans+=2;
		}
		
	}
	cout << ans;

	return 0;
}