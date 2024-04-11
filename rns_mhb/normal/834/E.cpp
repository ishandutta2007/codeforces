#include <bits/stdc++.h>
using namespace std;

long long L, R;
int a[30], b[30], num[12], pos, ans;

bool check(int cur, bool left, bool right) {
	if (cur == -1 || (!left && !right)) return true;
	int up = b[cur];
	if (!right) up = 9;
	int down = a[cur];
	if (!left) down = 0;
	if (up < down) return false;
	for (int i = down; i <= up; i ++) {
		if (!num[i]) continue;
		else {
			num[i] --;
			bool res = check(cur - 1, left && (i == a[cur]), right && (i == b[cur]));
			num[i] ++;
			if (res) return true;
		}
	}
	return false;
}

void dfs(int cur, int now) {
	if (cur == 9) {
		num[9] = now;
		if (check(pos - 1, 1, 1)) ans ++;
	}
	else {
		for (int i = 0; i <= now; i ++) {
			num[cur] = i;
			dfs(cur + 1, now - i);
		}
	}
}

int main() {
	scanf("%I64d%I64d", &L, &R);
	while (L) {
		a[pos ++] = L % 10;
		L /= 10;
	}
	pos = 0;
	while (R) {
		b[pos ++] = R % 10;
		R /= 10;
	}
	dfs(0, pos);
	printf("%d", ans);
	return 0;
}