#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	double L, v1, v2;
	int K;
	cin >> N >> L >> v1 >> v2 >> K;
	int g = (N + K - 1) / K;
	double va = (1 + (v2 - v1) / (v1 + v2)) * (g-1) * v1 + v2;
	double t = L / va;
	double r = t * (v2 - v1) / (v1 + v2);
	cout << setprecision(10) << fixed << t * g + r * (g-1) << endl;
	exit(0);
}