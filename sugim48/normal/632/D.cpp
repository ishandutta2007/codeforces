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
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N, M; cin >> N >> M;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	vector<int> b(M + 1);
	for (int i = 0; i < N; i++)
		if (a[i] <= M)
			b[a[i]]++;
	vector<int> c(M + 1);
	for (int x = 1; x <= M; x++)
		for (int y = x; y <= M; y += x)
			c[y] += b[x];
	int _x = 1;
	for (int x = 1; x <= M; x++)
		if (c[x] > c[_x])
			_x = x;
	cout << _x << ' ' << c[_x] << endl;
	for (int i = 0; i < N; i++)
		if (_x % a[i] == 0)
			printf("%d ", i + 1);
	cout << endl;
}