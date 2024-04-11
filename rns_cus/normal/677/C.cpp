#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 100100

char s[N];
int n, f[N];

int main() {
//	freopen("c.in", "r", stdin);
	for (int i = 0; i < 64; i ++) {
		for (int j = 0; j < 64; j ++) {
			for (int k = 0; k < 64; k ++) if ((j & k) == i) f[i] ++;
		}
	}
	scanf("%s", s);
	int len = strlen(s);
	long long ans = 1;
	for (int i = 0; i < len; i ++) {
		int x = 0;
		if (s[i] >= '0' && s[i] <= '9') x = s[i] - '0';
		else if (s[i] >= 'A' && s[i] <= 'Z') x = s[i] - 'A' + 10;
		else if (s[i] >= 'a' && s[i] <= 'z') x = s[i] - 'a' + 36;
		else if (s[i] == '-') x = 62;
		else x = 63;
		ans = ans * f[x] % mod;
	}
	cout << ans << endl;
	return 0;
}