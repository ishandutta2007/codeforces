#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E3 + 10;

int n, K;
bool vis[MAXN];

int main(){
	scanf("%d%d", &n, &K);
	for (int x, i = 0; i < K; ++i){
		scanf("%d", &x);
		if (x == n){
			puts("1");
			return 0;
		}
		vis[x] = true;
	}
	bitset<MAXN> ans, temp;
	ans.set(0);
	for (int i = 1; i <= MAXN; ++i){
		temp.reset();
		for (int j = 0; j < n; ++j)
			if (vis[j])
				temp |= ans >> n - j;
		for (int j = n + 1; j < MAXN; ++j)
			if (vis[j])
				temp |= ans << j - n;

		ans = temp;
		if (ans[0]){
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}