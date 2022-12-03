#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	vector<bool> p(2000001, true);
	p[0] = p[1] = false;
	for (int i = 2; i <= 2000000; i++)
		if (p[i])
			for (int j = i * 2; j <= 2000000; j += i)
				p[j] = false;
	int N; cin >> N;
	vector<int> a(N), num(1000001);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (a[i] == 1) num[a[i]]++;
		else num[a[i]] = 1;
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	N = a.size();
	int ma = 0, _x, _y = 0;
	for (int i = 0; i < N; i++) {
		int x = a[i];
		if (num[x] > ma) {
			ma = num[x];
			_x = x;
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			int x = a[i], y = a[j];
			if (p[x + y] && ma < num[x] + num[y]) {
				ma = num[x] + num[y];
				_x = x; _y = y;
			}
		}
	vector<int> ans;
	for (int t = 0; t < num[_x]; t++)
		ans.push_back(_x);
	for (int t = 0; t < num[_y]; t++)
		ans.push_back(_y);
	cout << ans.size() << endl;
	for (int x: ans) cout << x << ' ';
	cout << endl;
}