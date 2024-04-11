#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

ld a[300010];

ld ans[100010];

int main() {
	forn (i, 100010) {
		ans[i] = 0;
	}
	forn (i, 300010) {
		a[i] = 3e9l;
	}
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	int n;
	ld l, v1, v2;
	cin >> n >> l >> v1 >> v2;
	ld L = 2 * l;
	forn (i, n) {
		cin >> a[i];
		a[i + n] = a[i] + L;
		a[i + 2 * n] = a[i] + 2 * L;
	}
	l = l * v2 / (v1 + v2);
	int k = 0;
	while (a[k] < l) {
		k++;
	}
	ld t = 0, t1 = 0;
	int i = 0, j = k;
	while (t1 < L) {
		//cerr << t1 << ' ' << i << ' ' << j << endl;
		t = t1;
		int dk = 0;
		if (a[i] < a[j] - l) {
			t1 = a[i];
			dk = -1;
			i++;
		} else {
			t1 = a[j] - l;
			dk = 1;
			j++;
		}
		if (t1 < L) {
			ans[k] += t1 - t;
			k += dk;
		}
	}
	ans[k] += L - t;
	forn (i, n + 1) {
		ans[i] /= L;
		printf("%0.12lf\n", double(ans[i]));
	}
	cout << endl;
	return 0;
}