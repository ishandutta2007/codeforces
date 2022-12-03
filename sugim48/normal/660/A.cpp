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

ll gcd(ll a, ll b) {
	if (b == 0) return abs(a);
	else return gcd(b, a % b);
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];
	vector<int> b;
	for (int i = 0; i < N; i++) {
		b.push_back(a[i]);
		if (i + 1 < N && gcd(a[i], a[i + 1]) != 1)
			b.push_back(1);
	}
	cout << b.size() - N << endl;
	for (int x: b) cout << x << ' ';
	cout << endl;
}