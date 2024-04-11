#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E6 + 10, MAXM = 1E6 + 10;

int a[MAXN];
int cnt[MAXM], s[MAXM];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if (a[i] <= m)
			++cnt[a[i]];
	}
	int ans = 1;
	for (int i = 1; i <= m; ++i){
		for (int j = i; j <= m; j += i)
			s[j] += cnt[i];
		if (s[ans] < s[i])
			ans = i;
	}
	printf("%d %d", ans, s[ans]);
	bool flag = false;
	for (int i = 0; i < n; ++i)
		if (ans % a[i] == 0){
			printf("%c%d", "\n "[flag], i + 1);
			flag = true;
		}
	puts("");
	return 0;
}