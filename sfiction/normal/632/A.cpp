#include <cstdio>

const int MAXN = 40 + 5;

bool a[MAXN];

int main(){
	int n, p;
	long long s = 0, t = 0;
	scanf("%d%d", &n, &p);
	char str[10];
	for (int i = 0; i < n; ++i){
		scanf("%s", str);
		t += a[i] = !!str[4];
	}
	for (int i = n - 1; i >= 0; --i)
		s = s << 1 | a[i];
	printf("%I64d\n", (s * 2 - t) * (p >> 1));
	return 0;
}