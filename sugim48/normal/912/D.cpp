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

int N, M, r;
priority_queue<pair<ll, vector<int>>> pq;

void f(int i, int j, int dj) {
	if (!(0<=j && j<M)) return;
	int dy = min(N - r, i) - max(0, i - r + 1) + 1;
	int dx = min(M - r, j) - max(0, j - r + 1) + 1;
	pq.push({(ll)dy * dx, {i, j, dj}});
}

int main() {
	int k;
	cin >> N >> M >> r >> k;
	rep(i, N) f(i, (M - 1) / 2, -1), f(i, (M - 1) / 2 + 1, +1);
	ll sum = 0;
	rep(t, k) {
		auto z = pq.top(); pq.pop();
		sum += z.first;
		vector<int> a = z.second;
		int i = a[0], j = a[1], dj = a[2];
		f(i, j + dj, dj);
	}
	double ans = (double)sum / (N - r + 1) / (M - r + 1);
	printf("%.15f\n", ans);
}