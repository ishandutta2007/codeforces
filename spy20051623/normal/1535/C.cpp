#include <bits/stdc++.h>

using namespace std;

char s[200005];
int last[2][2];

void solve() {
	scanf("%s", s);
	memset(last, -1, sizeof last);//-1
	long long ans = 0;
	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		if (s[i] != '?') {//01
			ans += i - max(last[s[i] - '0'][(i & 1) ^ 1], last[(s[i] - '0') ^ 1][i & 1]);//0/1
			last[s[i] - '0'][i & 1] = i;
		} else {//maxmin
			ans += i - min(max(last[0][0], last[1][1]), max(last[0][1], last[1][0]));
		}
	}
	printf("%lld\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}