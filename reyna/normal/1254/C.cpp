
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
#define int long long
const int N = (int) 1e4 + 4, mod = (int) 0;
int p[N];
pair<int, int> sr[N];
int ask(int t, int i, int j, int k) {
	cout << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
	int x;
	cin >> x;
	return x;
}
int32_t main() {
	int n;
	cin >> n;
	p[0] = 0;
	int p0 = 0;
	int p1 = 1;
	for (int j = 2; j < n; ++j) {
		if (ask(2, p0, p1, j) < 0) {
			p1 = j;	
		}
	}
	int pt = 0;
	for (int j = 1; j < n; ++j) if (j != p1)
		sr[pt++] = mp(ask(1, p0, p1, j), j);
	sort(sr, sr + pt);
	int pmost = sr[pt - 1].second;
	p[0] = 0;
	p[1] = p1;
	int l = 2, r = n - 1;
	for (int j = 0; j < pt - 1; ++j) {
		int cur = sr[j].second;
		if (ask(2, p0, pmost, cur) > 0) {
			p[r--] = cur;
		} else {
			p[l++] = cur;
		}
	}
	p[l++] = pmost;
	cout << 0 << endl;
	for (int j = 0; j < n; ++j) cout << p[j] + 1 << ' ';
	cout << endl;
}