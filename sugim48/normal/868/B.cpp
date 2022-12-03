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

int main() {
	int T = 12*60*60;
	vector<int> a(T);
	int h, m, s; cin >> h >> m >> s; h %= 12;
	int t = (((h * 60) + m) * 60) + s;
	a[t % T]++, a[t * 12 % T]++, a[t * 12*60 % T]++;
	int t1, t2; cin >> t1 >> t2; t1 %= 12; t2 %= 12;
	if (t1 > t2) swap(t1, t2);
	t1 *= 60*60, t2 *= 60*60;
	int cnt = 0;
	for (int i = t1; i <= t2; i++) cnt += a[i];
	cout << (cnt == 0 || cnt == 3 ? "YES" : "NO") << endl;
}