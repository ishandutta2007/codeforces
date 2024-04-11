#include <cstdio>
#include <cstring>

const int MAXN = 100;

int cnt[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	bool flag = false;
	for (int i = 1; i <= n; ++i){
		memset(cnt, 0, sizeof(cnt));
		for (int t, j = 1; j <= n; ++j){
			scanf("%d", &t);
			++cnt[t];
		}
		int ans = 0;
		for (int j = 1; j <= n; ++j)
			if (cnt[ans] <= cnt[j])
				ans = j;
		if (ans == n - 1){
			if (flag)
				++ans;
			flag = true;
		}
		printf("%d%c", ans, "\n "[i < n]);
	}
	return 0;
}