
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

const int N = (int) 1005, mod = (int) 0;
int cnt[N];
int main() {
	int n, k;
	cin >> n >> k;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		cnt[--x]++;
	}
	int sum = 0;
	for (int j = 0; j < k; ++j)
		sum += (cnt[j] & 1);
	cout << n - sum / 2 << '\n';
}