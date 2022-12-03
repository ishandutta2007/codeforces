#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;
struct edge { int v, w; };

int main() {
	int N, M, K; cin >> N >> M >> K;
	if (K % 2) K++;
	vector<int> a(N, -1);
	for (;;) {
		bool ok = true;
		rep(i, N) if (a[i] == -1) ok = false;
		if (ok) break;
		int x; cin >> x, x--;
		int i;
		if (x < K / 2) for (i = 0; a[i] != -1 && a[i] <= x; i++);
		else for (i = N - 1; a[i] != -1 && a[i] >= x; i--);
		a[i] = x;
		cout << i + 1 << endl;
		fflush(stdout);
	}
}