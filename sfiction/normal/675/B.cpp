#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n, a[5];
	scanf("%d", &n);
	scanf("%d%d%d%d", &a[0], &a[1], &a[3], &a[2]);
	a[4] = a[0];
	int v1 = n << 2, v2 = 0;
	for (int i = 0; i < 4; ++i){
		v1 = min(v1, a[i] + a[i + 1]);
		v2 = max(v2, a[i] + a[i + 1]);
	}
	printf("%I64d\n", n * (long long)max(0, v1 + n - v2));
	return 0;
}