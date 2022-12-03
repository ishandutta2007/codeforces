#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
struct edge { int v, w; };
const ll INF = LLONG_MAX / 10;
const int MOD = 1e9 + 7;
const ll e18 = 1e18;

int main() {
	int n, m; cin >> n >> m;
	if (n <= 50) cout << m % (1LL<<n) << endl;
	else cout << m << endl;
}