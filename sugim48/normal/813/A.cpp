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

const int MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
const int INF = INT_MAX / 2;

int main() {
	int N; cin >> N;
	int sum = 0;
	while (N--) {
		int x; cin >> x;
		sum += x;
	}
	int M; cin >> M;
	while (M--) {
		int l, r; cin >> l >> r;
		sum = max(sum, l);
		if (sum <= r) {
			cout << sum << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}