#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<double, int> d_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const ll INF = LLONG_MAX / 10;
const int MOD = 1e9 + 7;

bool check(int N, int K, vector<int> a) {
	rep(i, N) if (!a[i]) return true;
	vector<int> b(1<<K);
	rep(i, N) b[a[i]]++;
	rep(x, 1<<K) rep(y, 1<<K)
		if (b[x] && b[y] && !(x & y))
			return true;
	return false;
}

int main() {
	int N, K; cin >> N >> K;
	vector<int> a(N);
	rep(i, N) rep(k, K) {
		int x; cin >> x;
		a[i] = a[i] * 2 + x;
	}
	cout << (check(N, K, a) ? "YES" : "NO") << endl;
}