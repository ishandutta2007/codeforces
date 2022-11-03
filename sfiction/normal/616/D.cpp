#include <cstdio>

const int MAXN = 5E5 + 10, MAXM = 1E6 + 10;

int a[MAXN];
int cnt[MAXM];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int tot = 0, l = 0;
	int ans = -1, sl, sr;
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		++cnt[a[i]];
		if (cnt[a[i]] == 1)
			++tot;
		for (; tot > k; ++l){
			--cnt[a[l]];
			if (cnt[a[l]] == 0)
				--tot;
		}
		if (ans < i - l + 1){
			ans = i - l + 1;
			sl = l, sr = i;
		}
	}
	printf("%d %d\n", sl + 1, sr + 1);
	return 0;
}