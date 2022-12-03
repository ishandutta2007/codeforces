#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, int> d_i;
const int MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
struct edge { int i, v, w; };

bool solve(int x, int y) {
	if (x == 1 && y == 0) return true;
	if (!(x >= 2 && y >= 1)) return false;
	int z = x + y - 1;
	if (z % 2) return false;
	z /= 2;
	return z <= y && y <= z * 2;
}

int main() {
	int x, y; cin >> y >> x;
	cout << (solve(x, y) ? "Yes" : "No") << endl;
}