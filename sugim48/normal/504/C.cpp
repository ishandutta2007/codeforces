#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;

int odd;

int f(int n, vector<int>& a, vector<int> b) {
	vector<int> c(n);
	int j;
	for (j = n; j - 1 > (n - 1) / 2; j--) {
		int x = a[j - 1];
		b[x]--; c[x]++;
		if (b[x] < c[x]) return j;
	}
	if (n % 2 == 1 && a[n / 2] != odd)
		return j;
	for (; j - 1 >= 0; j--)
		if (a[j - 1] != a[n - j])
			return j;
	return 0;
}

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		b[a[i]]++;
	odd = -1;
	for (int i = 0; i < n; i++) {
		if (b[i] % 2 == 0) continue;
		if (odd == -1 || odd == i) odd = i;
		else {
			cout << 0 << endl;
			return 0;
		}
	}
	int r = f(n, a, b);
	reverse(a.begin(), a.end());
	int l = n - f(n, a, b);
	reverse(a.begin(), a.end());
	ll sum = 0;
	for (int i = 0, j = n; i < j; i++, j--) {
		sum += max(0, min(l, j - 1) - i + 1);
		sum += max(0, j - max(r, i + 1) + 1);
		if (l >= i && j >= r) sum--;
		if (a[i] != a[j - 1]) break;
	}
	cout << sum << endl;
}