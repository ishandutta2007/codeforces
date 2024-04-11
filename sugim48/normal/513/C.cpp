#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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
struct edge { int u; ll V; int v; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int a[6] = {1, 3, 9, 27, 81, 243};

int main() {
	int n; cin >> n;
	vector<int> L(n), R(n);
	for (int i = 0; i < n; i++)
		cin >> L[i] >> R[i];
	double e = 0, sum = 0;
	for (int x = 1; x <= 10000; x++) {
		for (int S = 0; S < a[n]; S++) {
			double p = 1;
			bool ok = false;
			int T = S, cnt0 = 0, cnt1 = 0;
			for (int i = 0; i < n; i++) {
				if (T % 3 == 0) {
					cnt0++;
					if (x >= L[i] && x <= R[i])
						p /= R[i] - L[i] + 1;
					else p = 0;
				}
				else if (T % 3 == 1) {
					cnt1++;
					if (x < R[i])
						p *= (double)min(R[i] - L[i] + 1, R[i] - x) / (R[i] - L[i] + 1);
					else p = 0;
				}
				else
					if (x > L[i])
						p *= (double)min(R[i] - L[i] + 1, x - L[i]) / (R[i] - L[i] + 1);
					else p = 0;
				T /= 3;
			}
			if ((cnt0 >= 1 && cnt1 == 1) || (cnt0 >= 2 && cnt1 == 0)) {
				e += p * x;
				sum += p;
			}
		}
	}
	printf("%.15f\n", e);
}