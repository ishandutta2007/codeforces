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
	ll A, B; cin >> A >> B;
	ll x, y, z; cin >> x >> y >> z;
	cout << max(0LL, x*2 + y - A) + max(0LL, y + z*3 - B) << endl;
}