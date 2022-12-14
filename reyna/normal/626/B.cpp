//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 405;

int read() { int x; cin >> x; return x; }

bool dp[N][N][N];

void go(int r, int g, int b) {
	if (dp[r][g][b]) return;
	dp[r][g][b] = 1;
	if (r >= 2)
		go(r - 1, g, b);
	if (g >= 2)
		go(r, g - 1, b);
	if (b >= 2)
		go(r, g, b - 1);
	if (r >= 1 && g >= 1)
		go(r - 1, g - 1, b + 1);
	if (g >= 1 && b >= 1)
		go(r + 1, g - 1, b - 1);
	if (r >= 1 && b >= 1)
		go(r - 1, g + 1, b - 1);
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int len; cin >> len;
	string s; cin >> s;
	int r = 0, g = 0, b = 0;
	for (int i = 0; i < len; ++i) {
		if (s[i] == 'R')
			r++;
		if (s[i] == 'B')
			b++;
		if (s[i] == 'G')
			g++;
	}
	go(r, g, b);
	if (dp[0][0][1])
		cout << 'B';
	if (dp[0][1][0])
		cout << 'G';
	if (dp[1][0][0])
		cout << 'R';
}