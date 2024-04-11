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
#include <unordered_map>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-12;
int INF = INT_MAX / 2;

int main() {
	int N; cin >> N;
	vector<int> a(N), c1(N), c2(N);
	rep(i, N) scanf("%d", &a[i]);
	rep(i, N) scanf("%d", &c1[i]), c1[i]--;
	rep(i, N) scanf("%d", &c2[i]), c2[i]--;
	vector<bool> sold(N);
	vector<priority_queue<i_i> > pq(3);
	rep(i, N) {
		pq[c1[i]].push(i_i(-a[i], i));
		pq[c2[i]].push(i_i(-a[i], i));
	}
	int Q; cin >> Q;
	while (Q--) {
		int c; scanf("%d", &c); c--;
		while (pq[c].size() && sold[pq[c].top().second]) pq[c].pop();
		if (pq[c].empty()) printf("%d ", -1);
		else {
			int i = pq[c].top().second;
			sold[i] = true;
			printf("%d ", a[i]);
		}
	}
	cout << endl;
}