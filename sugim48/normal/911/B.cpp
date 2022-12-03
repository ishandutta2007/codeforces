#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;

int main() {
	 int n, a, b; cin >> n >> a >> b;
	 int ma = 0;
	 for (int x = 1; x <= n - 1; x++) {
		 int y = n - x;
		 if (x > a || y > b) continue;
		 int mi = min(a / x, b / y);
		 ma = max(ma, mi);
	 }
	 cout << ma << endl;
}