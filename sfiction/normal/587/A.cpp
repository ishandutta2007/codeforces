#include <cstdio>

const int MAXN = 1E6 + 200;

int cnt[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		++cnt[t];
	}
	int ans = 0;
	for (int i = 0; i < MAXN; ++i){
		cnt[i + 1] += cnt[i] >> 1;
		if (cnt[i] &= 1)
			++ans;
	}
	printf("%d\n", ans);
	return 0;
}