#define _USE_MATH_DEFINES
#include <algorithm>
#include <complex>
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
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<ll> a(N), b(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++)
		cin >> b[i];
	ll A = 0, B = 0;
	for (int i = 0; i < N; i++) {
		A |= a[i];
		B |= b[i];
	}
	cout << A + B << endl;
}