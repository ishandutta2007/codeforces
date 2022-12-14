
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

const int N = (int) 1e3 + 3, mod = (int) 0;
int a[N];
pair<int, int> b[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int cnt = 0;
	for (int j = 0; j < n; ++j)
		cin >> a[j];
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			cnt += (a[i] > a[j]);
	cout << cnt << endl;
	for (int cur = n - 1; cur >= 0; --cur) {
		int pt = 0;
		for (int i = 0; i < cur; ++i)
			if (a[i] > a[cur])
				b[pt++] = mp(a[i], i);
		sort(b, b + pt);
		for (int i = 0; i < pt; ++i)
			cout << b[i].second + 1 << ' ' << cur + 1 << '\n';
		
	}
}