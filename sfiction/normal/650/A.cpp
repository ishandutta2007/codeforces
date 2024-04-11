#include <cstdio>
#include <map>
#include <utility>

using namespace std;

typedef pair<int, int> PII;

int main(){
	int n, x, y;
	scanf("%d", &n);
	long long ans = 0;
	map<int, int> a, b;
	map<PII, int> c;
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &x, &y);
		if (a.count(x) == 0)
			a[x];
		if (b.count(y) == 0)
			b[y];
		if (c.count(PII(x, y)) == 0)
			c[PII(x, y)];
		ans += a[x]++;
		ans += b[y]++;
		ans -= c[PII(x, y)]++;
	}
	printf("%I64d\n", ans);
	return 0;
}