
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
	cout << "? ";
	for (int j = 1; j <= 100; ++j)
		cout << j << ' ';
	cout << endl;
	int res_right;
	cin >> res_right;
	res_right &= (1 << 14) - (1 << 7);
	cout << "? ";
	for (int j = 1; j <= 100; ++j)
		cout << (j << 7) << ' ';
	cout << endl;
	int res_left;
	cin >> res_left;
	res_left &= 127;
	cout << "! " << res_left + res_right << endl;
}