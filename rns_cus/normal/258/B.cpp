#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

typedef vector<int> VI;

VI calc(int x) {
	int cnt = 0;
	VI rt; rt.clear(); for(int i= 0; i < 10; i ++) rt.push_back(0);
	if(x < 10) {
		for(int i = 0; i <= x; i ++) if(i == 4 || i == 7) cnt ++;
		rt[0] = x + 1 - cnt; rt[1] = cnt;
		return rt;
	}
	int y = x / 10;
	while(y) {
		if(y % 10 == 4 || y % 10 == 7) cnt ++;
	 	y /= 10;
	}
	int cc = 0;
	for(int i = 0; i <= x % 10; i ++) {
		if(i == 4 || i == 7) cc ++;
	}
	rt[cnt] = x % 10 + 1 - cc;
	rt[cnt + 1] = cc;
	x = x / 10 - 1;
	VI tp = calc(x);
	for(int i = 0; i < 10; i ++) {
		rt[i] += 8 * tp[i];
		if(i < 9) rt[i + 1] += 2 * tp[i];
	}
	return rt;
}

VI a;
int ans, cnt[10], inv[10], I;

int C(int x, int y) {
	if(x < y) return 0;
	int rt = 1;
	for(int i = 0; i < y; i ++) {
		rt = 1LL * rt * (x - i) % mod;
		rt = 1LL * rt * inv[i + 1] % mod;
	}
	return rt;
}

void dfs(int r, int st, int sum) {
	if(r == 6) {
		int rt = 1;
		for(int i = 0; i < 10; i ++) if(cnt[i]) {
			rt = 1LL * rt * C(a[i], cnt[i]) % mod;
		}
		ans += 720LL * rt % mod * I % mod;
		if(ans >= mod) ans -= mod;
		return;
	}
	for(int i = st; i < 10 && i < sum; i ++) {
		cnt[i] ++;
		dfs(r + 1, i, sum - i);
		cnt[i] --;
	}
}

int main() {
	inv[1] = 1;
	for(int i = 2; i <= 6; i ++) {
		for(int j = 1; ; j ++) {
			if(1LL * j * mod % i == i - 1) {
				inv[i] = (1LL * j * mod + 1) / i;
				break;
			}
		}
	}
	int m;
    scanf("%d", &m);
    a = calc(m);
    a[0] --;
    for(int i = 1; i < 10; i ++) if(a[i]) {
		I = a[i];
    	dfs(0, 0, i);
    }
    printf("%d\n", ans);
	return 0;
}