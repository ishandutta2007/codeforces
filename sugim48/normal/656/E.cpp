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

int N, ma;
int a[10][10];

int f(int t, int T) {
	int i = t / N, j = t % N;
	cin >> a[i][j];
	t + 1 == T ? 0 : f(t + 1, T);
}

int g(int t, int T) {
	int k = t / N / N, i = t / N % N, j = t % N;
	a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	t + 1 == T ? 0 : g(t + 1, T);
}

int h(int t, int T) {
	int i = t / N, j = t % N;
	ma = max(ma, a[i][j]);
	t + 1 == T ? 0 : h(t + 1, T);
}

int main() {
	cin >> N;
	f(0, N * N);
	g(0, N * N * N);
	h(0, N * N);
	cout << ma << endl;
}