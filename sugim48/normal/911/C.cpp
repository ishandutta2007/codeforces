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
	 vector<int> k(3);
	 rep(i, 3) cin >> k[i];
	 rep(x0, 10) rep(x1, 10) rep(x2, 10) {
		 vector<int> x = {x0, x1, x2};
		 vector<bool> a(1000);
		 rep(i, 3) for (int y = x[i]; y < 1000; y += k[i]) a[y] = true;
		 int ma = max({x0, x1, x2});
		 bool ok = true;
		 for (int y = ma; y < 1000; y++) if (!a[y]) ok = false;
		 if (ok) {
			 cout << "YES" << endl;
			 return 0;
		 }
	 }
	 cout << "NO" << endl;
}