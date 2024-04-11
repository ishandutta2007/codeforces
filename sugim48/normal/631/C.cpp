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
	int N, M; cin >> N >> M;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	vector<int> t(M), r(M);
	for (int j = 0; j < M; j++)
		scanf("%d%d", &t[j], &r[j]);
	int ma = 0;
	vector<int> d(M);
	for (int j = M - 1; j >= 0; j--)
		if (r[j] > ma) {
			d[j] = r[j] - ma;
			ma = r[j];
		}
	sort(a.begin(), a.begin() + ma);
	vector<int> _a = a;
	int x = 0, y = ma, z = ma;
	for (int j = 0; j < M; j++) {
		if (t[j] == 1)
			while (d[j]--) {
				_a[z - 1] = a[y - 1];
				y--; z--;
			}
		if (t[j] == 2)
			while (d[j]--) {
				_a[z - 1] = a[x];
				x++; z--;
			}
	}
	for (int i = 0; i < N; i++)
		printf("%d ", _a[i]);
	cout << endl;
}