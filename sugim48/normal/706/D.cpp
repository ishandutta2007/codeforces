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
#include <random>
#include <list>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

struct node { int lch, rch, sz; };

ll MOD = 10007;
ll _MOD = 1000000009;
double EPS = 1e-10;

vector<node> a;
int ans;

void f(int k, int i, int x, int z) {
	a[k].sz += z;
	if (i == -1) return;
	int t = x>>i & 1;
	if (t == 0) {
		if (a[k].lch == -1) {
			a.push_back(node{-1, -1, 0});
			a[k].lch = a.size() - 1;
		}
		f(a[k].lch, i - 1, x, z);
	}
	else {
		if (a[k].rch == -1) {
			a.push_back(node{-1, -1, 0});
			a[k].rch = a.size() - 1;
		}
		f(a[k].rch, i - 1, x, z);
	}
}

void g(int k, int i, int x) {
	if (i == -1) return;
	int t = x>>i & 1;
	if (t == 0) {
		if (a[k].rch != -1 && a[a[k].rch].sz) {
			ans |= 1<<i;
			g(a[k].rch, i - 1, x);
		}
		else g(a[k].lch, i - 1, x);
	}
	else {
		if (a[k].lch != -1 && a[a[k].lch].sz) {
			ans |= 1<<i;
			g(a[k].lch, i - 1, x);
		}
		else g(a[k].rch, i - 1, x);
	}
}

int main() {
	a.push_back(node{-1, -1, 0});
	f(0, 30, 0, +1);
	int Q; cin >> Q;
	while (Q--) {
		string s; int x;
		cin >> s >> x;
		if (s == "+") f(0, 30, x, +1);
		if (s == "-") f(0, 30, x, -1);
		if (s == "?") {
			ans = 0;
			g(0, 30, x);
			printf("%d\n", ans);
		}
	}
}