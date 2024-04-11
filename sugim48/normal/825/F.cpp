#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;

const int MOD = 1e9 + 7;
const int INF = INT_MAX / 2;

vector<int> z_algorithm(string s) {
	int N = s.length();
	vector<int> a(N + 1); a[0] = N;
	int j = 0;
	for (int i = 1; i <= N;) {
		for (; i + j < N && s[i + j] == s[j]; j++);
		if (a[i] = j) {
			int k;
			for (k = 1; k + a[k] < a[i]; k++)
				a[i + k] = a[k];
			i += k; j -= k;
		}
		else i++;
	}
	return a;
}

int main() {
	string s; cin >> s;
	int N = s.length();
	vector<vector<short> > a(N + 1, vector<short>(N + 1));
	rep(l, N) {
		vector<int> z = z_algorithm(s.substr(l));
		for (int d = 1; d <= N - l; d++) {
			int T = z[d] / d + 1, r = l;
			for (int t = 1; t <= T; t++) {
				r += d;
				if (t > a[l][r]) a[l][r] = t;
			}
		}
	}
	vector<int> len(N + 1);
	for (int x = 1; x <= N; x++) len[x] = to_string(x).length();
	vector<int> dp(N + 1, INF);
	dp[0] = 0;
	rep(l, N) for (int r = l + 1; r <= N; r++) {
		int t = a[l][r];
		int x = dp[l] + len[t] + (r - l) / t;
		if (x < dp[r]) dp[r] = x;
	}
	cout << dp[N] << endl;
}