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
#include <unordered_map>
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
	int N, X; cin >> N >> X;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	vector<int> xs(N + 1);
	for (int i = 0; i < N; i++)
		xs[i + 1] = xs[i] ^ a[i];
	sort(xs.begin(), xs.end());
	ll ans = (ll)(N + 1) * (N + 1);
	while (X) {
		int z;
		for (z = 1; !(X & z); z <<= 1);
		X -= z;
		vector<int> v, w;
		for (int x: xs) {
			v.push_back(x / z);
			w.push_back((x / z) ^ (X / z));
		}
		sort(w.begin(), w.end());
		int i = 0, prev = -1, cnt;
		for (int x: v)
			if (x == prev) ans -= cnt;
			else {
				prev = x;
				cnt = 0;
				for (; i <= N && w[i] <= x; i++)
					if (w[i] == x)
						cnt++;
				ans -= cnt;
			}
	}
	cout << ans / 2 << endl;
}