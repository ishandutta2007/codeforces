#include <cstdio>

const int N = 100005;
bool np[N];
int n, a[N], tot;

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
		if (!np[i]) {
			++tot;
			for (int j = i; j <= n; j += i)
				if (!np[j])
					np[j] = true, a[j] = tot;
		}
	for (int i = 2; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}