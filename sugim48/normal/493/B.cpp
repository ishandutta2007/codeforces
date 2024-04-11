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
	int n; cin >> n;
	vector<int> vf, vs;
	ll sumf = 0, sums = 0;
	char last;
	while (n--) {
		int a; scanf("%d", &a);
		if (a > 0) {
			vf.push_back(a);
			sumf += a;
			last = 'f';
		}
		else {
			vs.push_back(-a);
			sums += -a;
			last = 's';
		}
	}
	if (sumf > sums) {
		cout << "first" << endl;
		return 0;
	}
	if (sumf < sums) {
		cout << "second" << endl;
		return 0;
	}
	int nf = vf.size(), ns = vs.size();
	for (int i = 0; i < min(nf, ns); i++) {
		if (vf[i] > vs[i]) {
			cout << "first" << endl;
			return 0;
		}
		if (vf[i] < vs[i]) {
			cout << "second" << endl;
			return 0;
		}
	}
	if (nf > ns) {
		cout << "first" << endl;
		return 0;
	}
	if (nf < ns) {
		cout << "second" << endl;
		return 0;
	}
	if (last == 'f') {
		cout << "first" << endl;
		return 0;
	}
	if (last == 's') {
		cout << "second" << endl;
		return 0;
	}
}