
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

const int N = (int) 105, mod = (int) 0;
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		if (k % 3 == 0) {
			if ((n % (k + 1)) % 3 == 0 && (n % (k + 1)) != k) {
				cout << "Bob\n";
			} else {
				cout << "Alice\n";
			}
		} else {
			if (n % 3 == 0) {
				cout << "Bob\n";
			} else {
				cout << "Alice\n";
			}
		}
	}
}