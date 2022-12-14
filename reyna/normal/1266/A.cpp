
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 0, mod = (int) 0;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int sum = 0;
		for (auto c : s) sum += (c - '0');
		if (sum % 3 != 0) {
			cout << "cyan\n";
			continue;
		}
		int has_zero = 0;
		for (auto c : s) if (c == '0') has_zero++;
		if (!has_zero) {
			cout << "cyan\n";
			continue;
		}
		int has_even = (has_zero > 1);
		for (auto c : s) if ((c - '0') % 2 == 0 && c != '0') has_even = 1;
		if (!has_even && sum > 0) {
			cout << "cyan\n";
			continue;
		}
		cout << "red\n";
	}
}