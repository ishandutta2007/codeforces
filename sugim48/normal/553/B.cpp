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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	vector<ll> fib(50);
	fib[0] = fib[1] = 1;
	for (int i = 2; i < 50; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		// cout << fib[i] << endl;
	}
	int n; ll k; cin >> n >> k;
	k--;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		p[i] = i + 1;
	for (int i = 0; i + 1 < n;)
		if (k < fib[n - i - 1]) i++;
		else {
			k -= fib[n - i - 1];
			swap(p[i], p[i + 1]);
			i += 2;
		}
	for (int i = 0; i < n; i++)
		cout << p[i] << ' ';
	cout << endl;
}