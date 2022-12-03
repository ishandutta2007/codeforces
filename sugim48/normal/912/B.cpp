#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const ll INF = INT_MAX / 2;
const int MOD = 1e9 + 7;
const ll e18 = 1e18;

int main() {
	ll x, y; cin >> x >> y;
	ll z;
	for (z = 1; z <= x; z *= 2);
	cout << (y == 1 ? x : z - 1) << endl;
}