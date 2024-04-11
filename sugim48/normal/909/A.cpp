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
	string s, t; cin >> s >> t;
	int N = s.length(), M = t.length();
	string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for (int n = 1; n <= N; n++)
		for (int m = 1; m <= M; m++)
				ans = min(ans, s.substr(0, n) + t.substr(0, m));
	cout << ans << endl;
}