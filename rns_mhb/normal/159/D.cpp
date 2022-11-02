#include <bits/stdc++.h>
using namespace std;

#define N 2020
char s[N];
int rad[N<<1];

void manacher(char *s) {
    int m = strlen(s) * 2 - 1;
    for (int i = 0, j = 0, k; i < m; i += k, j = max(j - k, 0)) {
        while (i - j >= 0 && i + j < m && s[i-j>>1] == s[i+j+1>>1]) j ++;
        rad[i] = j;
        for (k = 1; k <= rad[i] && k <= i && rad[i-k] != rad[i] - k; k ++)
            rad[i+k] = min(rad[i-k], rad[i] - k);
    }
}

typedef long long ll;

int func(int x, int y, int z, int w) {
	z = max(z, x);
	y = min(y, w);
	if (y < z) return (y - x + 1) * (w - z + 1);
	return (y - x + 1) * (w - z + 1) - (y - z + 2) * (y - z + 1) / 2;
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
	manacher(s);
	ll ans = 0;
	for (int i = 0; i < 2 * n - 1; i ++) for (int j = i + 1; j < 2 * n - 1; j ++) {
		ans += func((i + 1) / 2, (i + rad[i] - 1) / 2, (j + 1 - rad[j]) / 2, j / 2);
	}
	cout<<ans<<endl;
}