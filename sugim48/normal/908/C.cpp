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
	int N, r; cin >> N >> r;
	vector<int> x(N);
	rep(i, N) cin >> x[i];
	vector<double> y(N);
	rep(i, N) {
		double ma = r;
		rep(j, i) {
			int dx = abs(x[i] - x[j]);
			if (dx == r * 2) ma = max(ma, y[j]);
			else if (dx < r * 2) {
				double dy = sqrt(4.0 * r * r - dx * dx);
				ma = max(ma, y[j] + dy);
			}
		}
		y[i] = ma;
	}
	rep(i, N) printf("%.15f ", y[i]);
	cout << endl;
}