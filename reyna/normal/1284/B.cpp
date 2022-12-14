
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
vector<int> a[N];
int most[N], least[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n, pt = 0;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int m;
		cin >> m;
		while (m--) {
			int x;
			cin >> x;
			a[j].pb(x);
		}
		int ascent = 0;
		for (int i = 0; i < (int) a[j].size() - 1; ++i) {
			if (a[j][i] < a[j][i + 1]) {
				ascent = 1;
			}
		}
		if (!ascent) {
			least[pt] = a[j].back();
			most[pt++] = a[j][0];
		}
	}
	sort(least, least + pt);
	sort(most, most + pt);
	long long res = 0;
	for (int j = 0; j < pt; ++j) {
		int pos = upper_bound(most, most + pt, least[j]) - most;
		res += pos;
	}
	cout << (LL) n * n - res << endl;
	
}