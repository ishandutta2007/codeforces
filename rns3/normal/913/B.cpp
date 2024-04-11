#include <bits/stdc++.h>

using namespace std;



#define N 10101



int p[N], n;

bool vis[N];

int cnt[N];



int main() {

	scanf("%d", &n);

	for (int i = 2; i <= n; i ++) scanf("%d", &p[i]), vis[p[i]] = 1;

	for (int i = 1; i <= n; i ++) if (!vis[i]) cnt[p[i]] ++;

	bool flag = 1;

	for (int i = 1; i <= n; i ++) if (vis[i] && cnt[i] < 3) flag = 0;

	puts(flag ? "Yes" : "No");



	return 0;

}