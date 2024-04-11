#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1E5 + 10;

int n;
PII a[MAXN];
int f[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].st, &a[i].nd);
	sort(a, a + n);
	int ans = n;
	for (int i = 0; i < n; ++i){
		int j = lower_bound(a, a + i, PII(a[i].st - a[i].nd, 0)) - a;
		f[i] = i - j + (j ? f[j - 1] : 0);
		ans = min(ans, f[i] + n - i - 1);
	}
	printf("%d\n", ans);
	return 0;
}