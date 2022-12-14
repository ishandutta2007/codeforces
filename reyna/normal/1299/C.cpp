
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

const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N];
struct seg {
	long long sum;
	int len;
	seg(int x) { sum = x; len = 1; }
	seg() {
		len = 0;
		sum = 0;
	}
};
vector<seg> res;
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; --i) {
		seg cur = seg(a[i]);
		while (res.size() >= 1 && (double) cur.sum / cur.len > ((double) cur.sum + res.back().sum) / (cur.len + res.back().len)) {
			cur.sum += res.back().sum;
			cur.len += res.back().len;
			res.pop_back();
		}
		res.push_back(cur);
	}
	reverse(ALL(res));
	cout << setprecision(10) << fixed;
	for (seg s : res) {
		for (int j = 0; j < s.len; ++j)
			cout << (double) s.sum / s.len << '\n';
	}
}