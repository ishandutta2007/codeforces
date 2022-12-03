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

string s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"";
string s2 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";

ll len[100010];

char solve(int N, ll i) {
	if (!N) return i < s0.length() ? s0[i] : '.';
	if (i < s1.length()) return s1[i];
	i -= s1.length();
	if (i < len[N - 1]) return solve(N - 1, i);
	i -= len[N - 1];
	if (i < s2.length()) return s2[i];
	i -= s2.length();
	if (i < len[N - 1]) return solve(N - 1, i);
	i -= len[N - 1];
	if (i < s3.length()) return s3[i];
	i -= s3.length();
	return '.';
}

int main() {
	len[0] = s0.length();
	for (int N = 1; N <= 100000; N++) {
		len[N] = s1.length() + len[N - 1] + s2.length() + len[N - 1] + s3.length();
		if (len[N] > 2e18) len[N] = 2e18;
	}
	int Q; cin >> Q;
	string ans(Q, ' ');
	rep(k, Q) {
		int N; ll i; cin >> N >> i;
		ans[k] = solve(N, i - 1);
	}
	cout << ans << endl;
}