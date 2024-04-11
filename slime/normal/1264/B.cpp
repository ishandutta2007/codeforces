#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;

int a[4];
int cur[maxn];
void work(int x, int y, int z, int w, int tp) {
	if (x + z < y + w) return;
	if (x + z >= y + w + 2) return ;	
	int nlen = x + y + z + w;
	for (int pl = 1; pl <= nlen; pl += 2) {
		if (x) cur[pl] = 0, x--;
		else cur[pl] = 2, z--;
	}
	for (int pl = 2; pl <= nlen; pl += 2) {
		if (y) cur[pl] = 1, y--;
		else cur[pl] = 3, w--;
	}
	for (int pl = 1; pl < nlen; pl++)
		if (abs(cur[pl] - cur[pl + 1]) != 1) return ;
	printf("YES\n");
	for (int i = 1; i <= nlen; i++) {
		if (tp) printf("%d ", 3 - cur[i]);
		else printf("%d ", cur[i]);
	}
	exit(0);
}
int main() {
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	work(a[0], a[1], a[2], a[3], 0);
	work(a[3], a[2], a[1], a[0], 1);
	printf("NO\n");
	return 0;
}