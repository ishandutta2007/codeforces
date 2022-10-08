#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
#define abs(x) ((x) > 0 ? (x) : -(x))

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int m, n, tot;
int v[200][200];

void work()
{
	tot = 1;
	for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
		v[i][j] = tot;
		tot += 2;
		if (tot > m * n) tot = 2;
	}
	/*
	for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
		for (int k = 0; k < 4; ++k) {
			int ux = i + dx[k], uy = j + dy[k];
			if (ux >= 1 && ux <= m && uy >= 1 && uy <= n && abs(v[i][j] - v[ux][uy]) == 1) {
				printf("%d %d\n", m, n);
				return;
			}
		}
	}
	*/
}

int main()
{
	//for (m = 1; m <= 100; ++m) for (n = 1; n <= 100; ++n) work();
	scanf("%d%d", &m, &n);
	if (m == 1 && n == 2 || m == 1 && n == 3 || m == 3 && n == 1 ||
		m == 2 && n == 1 || m == 2 && n == 2) {
			printf("%d\n", -1);
			return 0;
		}
	if (m == 1 && n == 4) {
		printf("2 4 1 3\n");
		return 0;
	}
	if (m == 3 && n == 2) {
		printf("1 4\n5 2\n3 6\n");
		return 0;
	}
	if (m == 4 && n == 1) {
		printf("2\n4\n1\n3\n");
		return 0;
	}
	if (m == 2 && n == 3) {
		printf("4 2 6\n1 5 3\n");
		return 0;
	}
	bool flag = false;
	if (m == 2) {
		swap(m, n);
		flag = true;
	}
	work();
	if (!flag) for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) printf("%d ", v[i][j]);
		printf("\n");
	} else
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= m; ++i) printf("%d ", v[i][j]);
		printf("\n");
	}
}