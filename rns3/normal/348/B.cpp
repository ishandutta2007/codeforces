#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long LL;

int n, chi[N], ini[N];
LL wei[N], atl[N], INF, good[N], bad[N];
int lev[N];

bool flag = 0;

vector <int> v[N];

LL __lcm(LL a, LL b) {
	return a / __gcd(a, b) * b;
}

void calc_chi() {
	int q[N], e = 1, now;
	q[1] = 1;
	lev[1] = 1;
	for (int f = 1; f <= e; f ++) {
		now = q[f];
		chi[now] = 0;
		for (int i = 0, sz = v[now].size(); i < sz; i ++) {
            if (!lev[v[now][i]]) {
				q[++e] = v[now][i];
				chi[now] ++;
				lev[v[now][i]] = lev[now] + 1;
            }
		}
	}
}

void Dfs(int rt) {
    for (int i = 0, sz = v[rt].size(); i < sz; i ++) if (lev[rt] < lev[v[rt][i]]) {
		Dfs(v[rt][i]);
		atl[rt] = __lcm(atl[rt], atl[v[rt][i]]);
		if (atl[rt] > INF) {
			flag = 1;
			break;
		}
    }
    atl[rt] *= max(1, chi[rt]);
    if (atl[rt] > INF) flag = 1;
    if (flag) return;
}

void dfs(int rt) {
	for (int i = 0, sz = v[rt].size(); i < sz; i ++) if (lev[rt] < lev[v[rt][i]]) {
        dfs(v[rt][i]);
		bad[rt] += bad[v[rt][i]];
	}
}

void calc_good() {
	int q[N], e = 1, now;
	q[1] = 1;
	good[1] = atl[1];
	for (int f = 1; f <= e; f ++) {
		now = q[f];
		for (int i = 0, sz = v[now].size(); i < sz; i ++) {
            if (lev[v[now][i]] > lev[now]) {
				q[++e] = v[now][i];
				good[q[e]] = good[now] / chi[now];
            }
		}
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &ini[i]);
		bad[i] = ini[i];
		INF += ini[i];
	}
	int x, y;
	for (int i = 1; i < n; i ++) {
		scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
	}
	calc_chi();
	for (int i = 1; i <= n; i ++) atl[i] = 1;
	Dfs(1);
	if (flag) {
		printf("%I64d\n", INF);
		return 0;
	}
	calc_good();
	dfs(1);
	LL ans = INF;
	for (int i = 1; i <= n; i ++) {
		ans = min(ans, bad[i] / good[i]);
	}
	printf("%I64d\n", INF - good[1] * ans);
	return 0;
}