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

char c[10], s[30];

int main() {
	int Q; cin >> Q;
	vector<int> a(1<<20);
	while (Q--) {
		scanf("%s %s", c, s);
		int N = strlen(s), x = 0;
		for (int i = 0; i < N; i++)
			x = x * 2 + (s[i] - '0') % 2;
		if (c[0] == '+') a[x]++;
		if (c[0] == '-') a[x]--;
		if (c[0] == '?') printf("%d\n", a[x]);
	}
}