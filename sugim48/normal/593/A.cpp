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
	int n; cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ma = 0;
	for (char c = 'a'; c <= 'z'; c++)
		for (char d = c + 1; d <= 'z'; d++) {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				bool ok = true;
				for (int j = 0; j < a[i].length(); j++)
					if (a[i][j] != c && a[i][j] != d)
						ok = false;
				if (ok) sum += a[i].length();
			}
			ma = max(ma, sum);
		}
	cout << ma << endl;
}