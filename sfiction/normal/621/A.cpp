#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	long long ans = 0;
	int m = 1 << 30;
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		ans += t;
		if (t & 1)
			m = min(m, t);
	}
	if (ans & 1)
		ans -= m;
	printf("%I64d\n", ans);
	return 0;
}