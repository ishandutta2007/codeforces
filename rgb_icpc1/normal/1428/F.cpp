#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MX 500005
#define MM 2000005
char s[MX];
LL dp[MX];
int fen[MM];

void update(int p, int v) {
	for(int k = p; k; k -= k & (-k)) fen[k] = max(fen[k], v);
}

int get(int p) {
	int ret = 0;
	for(int k = p; k < MM; k += k & (-k)) ret = max(ret, fen[k]);
	return ret;
}

int main() {
//	freopen("in.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N; cin >> N;
	cin >> s;
	
	dp[0] = (s[0] == '1');
	int L = (dp[0] == 1);
	if(L) update(L, 1);
	for(int i = 1; i < N; i ++) {
		if(s[i] == '0') dp[i] = dp[i - 1], L = 0;
		else {
			L ++;
			int pos = get(L);
			if(pos) dp[i] = dp[i - 1] + i - pos + L;
			else dp[i] = dp[i - 1] + i + 1;
			update(L, i + 1);
		}
	}
	LL ans = 0;
	for(int i = 0; i < N; i ++) ans += dp[i];
	cout << ans << endl;
	
	return 0;
}