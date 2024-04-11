#include <bits/stdc++.h>
using namespace std;
#define M 3000

int n;
struct pnt{
	int x, y;
	pnt(int x = 0, int y = 0) : x(x), y(y){};
} p[M];
bool operator<(pnt a, pnt b) {
	return a.x != b.x ? a.x < b.x : a.y < b.y;
}

int m;
pnt q[M*M];

int main() {
	//freopen("D1.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++) {
		//printf("%d %d\n", p[i].x, p[i].y);
	}
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
		q[++m] = pnt(p[j].x - p[i].x, p[j].y - p[i].y);
		//printf("i = %d, j = %d;%d %d\n", i, j, q[m].x, q[m].y);
	}
	//printf("m = %d\n", m);
	sort(q + 1, q + m + 1);

	long long rlt = 0;
	for (int j, i = 1; i <= m; i = j) {
		for (j = i; j <= m; j++) if (q[j].x != q[i].x || q[j].y != q[i].y) {
			break;
		}
		//printf("i = %d, j = %d\n", i, j);
        rlt += 1ll * (j - i) * (j - i - 1) / 2;
	}
	printf("%I64d\n", rlt / 2);
	return 0;
}