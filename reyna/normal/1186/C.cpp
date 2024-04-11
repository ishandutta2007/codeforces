
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
	string a, b;
	cin >> a >> b;
	int parity = 0;
	for (auto c : b) parity ^= c - '0';
	int res = 0, cur_parity = 0;
	for (int j = 0; j < (int) a.size(); ++j) {
		cur_parity ^= a[j] - '0';
		if (j - (int) b.size() >= 0) cur_parity ^= a[j - (int) b.size()] - '0';
		if (j + 1 >= (int) b.size()) {
			res += cur_parity ^ parity ^ 1;	
		}
	}
	cout << res << endl;
}