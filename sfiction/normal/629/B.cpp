#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 4E2 + 10;

int a[MAXN], b[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	char s[10];
	int l, r;
	for (int i= 0; i < n; ++i){
		scanf("%s%d%d", s, &l, &r);
		if (s[0] == 'M')
			++a[l], --a[++r];
		else
			++b[l], --b[++r];
	}
	int ans = 0;
	for (int i = 1; i < MAXN; ++i){
		a[i] += a[i - 1], b[i] += b[i - 1];
		ans = max(ans, min(a[i], b[i]));
	}
	printf("%d\n", ans << 1);
	return 0;
}