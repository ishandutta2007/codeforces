#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E2 + 10;

int a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	n = unique(a, a + n) - a;
	bool flag = false;
	for (int i = 2; i < n; ++i)
		flag |= a[i - 2] + 2 == a[i];
	puts(flag ? "YES" : "NO");
	return 0;
}