#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10;
const int INF = 1E9 + 10;

int n;
int a[MAXN];

int main(){
	scanf("%d", &n);
	int val = INF;
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		val = min(val, a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] == val){
			int cnt = 0;
			for (int j = (i + 1) % n; a[j] > val; j = (j + 1) % n)
				++cnt;
			ans = max(cnt, ans);
		}
	printf("%I64d\n", ans + (ll)n * val);
	return 0;
}