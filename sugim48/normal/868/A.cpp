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

bool check(string s, int N, vector<string> a) {
	rep(i, N) if (a[i] == s) return true;
	rep(i, N) rep(j, N) if (a[i][1] == s[0] && a[j][0] == s[1]) return true;
	return false;
}

int main() {
	string s; cin >> s;
	int N; cin >> N;
	vector<string> a(N);
	rep(i, N) cin >> a[i];
	cout << (check(s, N, a) ? "YES" : "NO") << endl;
}