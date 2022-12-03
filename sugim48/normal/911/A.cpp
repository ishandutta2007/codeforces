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
	vector<int> a(N);
	rep(i, N) cin >> a[i];
	int mi = INF;
	rep(i, N) mi = min(mi, a[i]);
	vector<int> v;
	rep(i, N) if (a[i] == mi) v.pb(i);
	int M = v.size(), ans = INF;
	rep(j, M - 1) ans = min(ans, v[j + 1] - v[j]);
	cout << ans << endl;
}