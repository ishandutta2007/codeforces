#include <bits/stdc++.h>
using namespace std;

#define N 2000100

char s[N];
int gas[N], sum[N], rmq[N][20], query, L, R;

int main() {
///	freopen("in.txt", "r", stdin);
	scanf("%s", s + 1);
///	puts(s + 1);
	int len = strlen(s + 1);
	for(int i = 1; i <= len; i ++){
		if(s[i] == '(') sum[i] = sum[i-1] - 1;
		else sum[i] = sum[i-1] + 1;
		if(s[i] == ')') gas[i] = gas[i-1] + 1;
		else gas[i] = gas[i-1];

	}//puts("");
	for(int j = 1; j <= len; j ++) rmq[j][0] = sum[j];
	for(int i = 1; i <= 20; i ++){
		for(int j = 1; j + (1 << i) <= len + 1; j ++){
			rmq[j][i] = max(rmq[j][i-1], rmq[j + (1<<(i-1))][i-1]);
		}//uts("");
	}
	for(scanf("%d", &query); query --; ){

		scanf("%d %d", &L, &R);

	///	cout << L << " " << R << endl;

		int ttt = gas[R] - gas[L-1];

		int kk = 31 - __builtin_clz(R - L + 1);

		int mx = max(0, max(rmq[L][kk], rmq[R-(1<<kk)+1][kk]) - sum[L-1]);

		int ans = (ttt - mx) * 2;
		printf("%d\n", ans);
	}
}