#include <stdio.h>
#include <algorithm>
using namespace std;
int inp[10000];
int main() {
	int n;
	scanf("%d", &n);
	int nn = (1<<n+1)-1;
	for (int i=2; i<=nn; i++) scanf("%d", &inp[i]);
	int ans = 0;

	for (int i=nn/2; i>0; i--) {
		int maa = max(inp[i*2], inp[i*2+1]);
		ans += maa * 2 - inp[i*2] - inp[i*2+1];
		inp[i] += maa;
	}
	printf("%d\n", ans);
	return 0;
}