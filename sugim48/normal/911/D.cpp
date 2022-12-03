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
	int N; cin >> N;
	vector<int> p(N);
	rep(i, N) cin >> p[i], p[i]--;
	int inv = 0;
	rep(i, N) for (int j = i + 1; j < N; j++) if (p[i] > p[j]) inv++;
	int Q; cin >> Q;
	while (Q--) {
		int l, r; scanf("%d%d", &l, &r), l--;
		int d = r - l, m = d * (d - 1) / 2;
		inv = (inv + m) % 2;
		if (inv % 2 == 0) printf("even\n");
		else printf("odd\n");
	}
}