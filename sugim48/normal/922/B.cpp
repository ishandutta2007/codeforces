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

int main() {
	int n; cin >> n;
	int ans = 0;
	for (int a = 1; a <= n; a++)
		for (int b = a; b <= n; b++) {
			int c = a ^ b;
			if (b <= c && c <= n && c < a + b) ans++;
		}
	cout << ans << endl;
}