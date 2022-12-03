#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <complex>
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
struct edge { int v; ll w; };

int MOD = 1000000007;

int main() {
	int N, H, W; cin >> N >> H >> W;
	if (N > H * W) {
		cout << -1 << endl;
		return 0;
	}
	vector<vector<int> > a(H, vector<int>(W));
	int odd = 1, even = 2;
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++) {
			if ((y + x) % 2 == 0 && odd <= N) {
				a[y][x] = odd;
				odd += 2;
			}
			if ((y + x) % 2 == 1 && even <= N) {
				a[y][x] = even;
				even += 2;
			}
		}
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++)
			cout << a[y][x] << ' ';
		cout << endl;
	}
}