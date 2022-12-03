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
struct edge { int src, dst; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-9;
ll INF = LLONG_MAX / 2;

int main() {
	int N, K; cin >> N >> K;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	vector<ll> sum(N + 1);
	rep(i, N) sum[i + 1] = sum[i] + a[i];
	int cnt = 0;
	ll tot = 0;
	for (int l = 0; l + K <= N; l++) {
		cnt++;
		tot += sum[l + K] - sum[l];
	}
	printf("%.15f\n", (double)tot / cnt);
}