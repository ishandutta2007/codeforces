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

int main() {
	int N, M, K; cin >> N >> M >> K;
	vector<int> p(K);
	for (int k = 0; k < K; k++)
		cin >> p[k];
	int sum = 0;
	while (N--) {
		for (int i = 0; i < M; i++) {
			int a; cin >> a;
			int k;
			for (k = 0; p[k] != a; k++);
			sum += k + 1;
			p.erase(p.begin() + k);
			p.insert(p.begin(), a);
		}
	}
	cout << sum << endl;
}