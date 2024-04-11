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
#include <random>
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

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector<int> ans(N);
	for (int l = 0; l < N; l++) {
		vector<int> b(N);
		int _k = 0;
		for (int i = l; i < N; i++) {
			int k = a[i];
			b[k]++;
			if (b[k] > b[_k]) _k = k;
			else if (b[k] == b[_k] && k < _k) _k = k;
			ans[_k]++;
		}
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << ' ';
	cout << endl;
}