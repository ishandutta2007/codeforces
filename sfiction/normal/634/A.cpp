#include <cstdio>

const int MAXN = 2E5 + 10;

int n;
int n1, n2;
int a[MAXN], b[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + n1), n1 += !!a[n1];
	for (int i = 0; i < n; ++i)
		scanf("%d", b + n2), n2 += !!b[n2];
	if (n1 != n2)
		puts("NO");
	else{
		int p = 0;
		for (; p < n1 && a[0] != b[p]; ++p);
		for (int i = 1; i < n1; ++i)
			if (a[i] != b[(i + p) % n1]){
				p = n1;
				break;
			}
		puts(p < n1 ? "YES" : "NO");
	}
	return 0;
}