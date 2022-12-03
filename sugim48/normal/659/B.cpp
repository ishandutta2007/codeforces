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

char s[100000][11];

int main() {
	int N, M; cin >> N >> M;
	vector<vector<i_i> > a(M);
	for (int i = 0; i < N; i++) {
		int j, x;
		scanf("%s%d%d", s[i], &j, &x);
		a[j - 1].push_back(make_pair(x, i));
	}
	for (int j = 0; j < M; j++) {
		sort(a[j].begin(), a[j].end());
		reverse(a[j].begin(), a[j].end());
		if (a[j].size() >= 3 && a[j][1].first == a[j][2].first)
			printf("?\n");
		else
			printf("%s %s\n", s[a[j][0].second], s[a[j][1].second]);
	}
}