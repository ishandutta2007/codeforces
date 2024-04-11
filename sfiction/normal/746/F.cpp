#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 2E5 + 10;

int n, w, K;
int a[MAXN], sa[MAXN];
int t[MAXN], st[MAXN], loc[MAXN];
PII b[MAXN];

int s[MAXN][2];

void update(int i, int c0, int c1){
	for (; i <= n; i = (i | i - 1) + 1)
		s[i][0] += c0, s[i][1] += c1;
}

int count(){
	int i = 0, step = 1 << 31 - __builtin_clz(n);
	int t = w, sum = 0;
	for (; step; step >>= 1)
		if (i + step <= n && s[i + step][0] <= t){
			t -= s[i += step][0];
			sum += s[i][1];
		}
	return sum;
}

int main(){
	scanf("%d%d%d", &n, &w, &K);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		sa[i] = sa[i - 1] + a[i];
	}
	for (int i = 1; i <= n; ++i){
		scanf("%d", &t[i]);
		st[i] = st[i - 1] + t[i];
		b[i] = PII(t[i] >> 1, i);
	}
	sort(b + 1, b + n + 1);
	reverse(b + 1, b + n + 1);
	for (int i = 1; i <= n; ++i)
		loc[b[i].nd] = i;
	int ans = 0;
	for (int r = 1, i = 1; i <= n; ++i){
		while (st[r - 1] - st[i - 1] - count() <= K){
			ans = max(ans, sa[r - 1] - sa[i - 1]);
			if (r > n)
				break;
			update(loc[r], 1, t[r] >> 1);
			++r;
		}
		update(loc[i], -1, -(t[i] >> 1));
	}
	printf("%d\n", ans);
	return 0;
}