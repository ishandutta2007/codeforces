#include <cstdio>

typedef long long ll;

const int MAXN = 4E3 + 10;

ll v[MAXN], d[MAXN], p[MAXN];
bool leave[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%I64d%I64d%I64d", &v[i], &d[i], &p[i]);
		leave[i] = false;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		if (leave[i])
			continue;

		++ans;
		ll vs = v[i], ds = 0;
		for (int j = i + 1; j <= n; ++j)
			if (!leave[j]){
				p[j] -= vs + ds;
				if (vs > 0)
					--vs;
				if (p[j] < 0){
					leave[j] = true;
					ds += d[j];
				}
			}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i)
		if (!leave[i])
			printf("%d ", i);
	return 0;
}