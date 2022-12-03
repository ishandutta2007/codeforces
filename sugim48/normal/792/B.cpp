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
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };

const int MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
ll INF = LLONG_MAX / 3;

int main() {
	int N, M; cin >> N >> M;
	vector<int> p(N);
	rep(i, N) p[i] = i;
	int prev = 0;
	while (M--) {
		int i;
		for (i = 0; p[i] != prev; i++);
		int x; cin >> x;
		i = (i + x) % N;
		cout << p[i] + 1 << ' ';
		prev = p[(i + 1) % N];
		N--;
		p.erase(p.begin() + i);
	}
	cout << endl;
}