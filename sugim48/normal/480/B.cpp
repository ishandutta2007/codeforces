#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
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
struct edge { int u, v; ll w; int i; bool used; };
 
int MOD = 1000000007;

i_i calc(vector<int>& a, int x) {
	int n = a.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j < n && a[j] - a[i] < x) j++;
		if (j < n && a[j] - a[i] == x)
			return i_i(i, j);
	}
	return i_i(-1, -1);
}

i_i _calc(vector<int>& a, int x) {
	int n = a.size(), j = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		while (j >= 0 && a[i] - a[j] < x) j--;
		if (j >= 0 && a[i] - a[j] == x)
			return i_i(i, j);
	}
	return i_i(-1, -1);
}

int main() {
	int n, l, x, y;
	cin >> n >> l >> x >> y;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	i_i p = calc(a, x), q = calc(a, y);
	if (p.first != -1 && q.first != -1)
		cout << 0 << endl;
	else if (p.first == -1 && q.first != -1)
		cout << 1 << endl << x << endl;
	else if (p.first != -1 && q.first == -1)
		cout << 1 << endl << y << endl;
	else {
		i_i t = calc(a, x + y);
		i_i r = calc(a, y - x), s = _calc(a, y - x);
		if (t.first != -1)
			cout << 1 << endl << a[t.first] + x << endl;
		else if (r.first != -1 && a[r.first] + y <= l)
			cout << 1 << endl << a[r.first] + y << endl;
		else if (s.first != -1 && a[s.first] - y >= 0)
			cout << 1 << endl << a[s.first] - y << endl;
		else
			cout << 2 << endl << x << ' ' << y << endl;
	}
}