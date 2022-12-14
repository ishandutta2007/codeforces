
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

const int N = (int) 5005, mod = (int) 0;

int main() {
	int n, m;
	cin >> n >> m;
	int cur = 0;
	vector<int> res;
	for (int i = 0; i < n; ++i) {
		cur += i / 2;
		if (cur >= m) {
			cur -= i / 2;
			for (int add = 0; add <= i; ++add) {
				if ((i - add) / 2 + cur == m) {
					res.pb(add + i+1);
					break;
				}
			}
			int st = 5e8;
			for (int j = 0; j < n - (i + 1); ++j) {
				res.pb(st);
				st += 20000;
			}
			for (int x : res) cout << x << ' ';
			cout << endl;
			return 0;
		}
		res.pb(i+1);
	}
	cout << -1 << endl;
	
}