
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
	int n;
	cin >> n;
	cout << 4 + n * 3 << '\n';
	for (int j = 0; j < n + 2; ++j)
		cout << j + 1 << ' ' << j + 1 << '\n';
	for (int j = 0; j < n + 1; ++j) {
		cout << j + 2 << ' ' << j + 1 << '\n';
		cout << j + 1 << ' ' << j + 2 << '\n';
	}
}