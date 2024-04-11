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
#include <unordered_set>
#include <complex>
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
struct edge { int v; ll w; };
// typedef complex<double> C;
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 2;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<int> f(N);
	rep(i, N) scanf("%d", &f[i]), f[i]--;
	rep(i, N) if (f[f[i]] != f[i]) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> F = f;
	sort(F.begin(), F.end());
	F.erase(unique(F.begin(), F.end()), F.end());
	int M = F.size();
	vector<int> g(N);
	rep(i, N) g[i] = lower_bound(F.begin(), F.end(), f[i]) - F.begin();
	vector<int> h(M);
	rep(j, M) h[j] = F[j];
	cout << M << endl;
	rep(i, N) printf("%d ", g[i] + 1);
	cout << endl;
	rep(j, M) printf("%d ", h[j] + 1);
	cout << endl;
}