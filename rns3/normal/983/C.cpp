#include <bits/stdc++.h>

using namespace std;



const int INF = 1e9;



#define x ftf[0]

#define y ftf[1]

#define z ftf[2]

#define t ftf[3]



int e;



#define M 808



const int K = 10;



int id[K][K][K][K];



int tmp[4];



struct bag {

	int ftf[4];

	int erase(int k) {

		tmp[0] = x;

		tmp[1] = y;

		tmp[2] = z;

		tmp[3] = t;

		tmp[k] = 0;

		sort(tmp, tmp + 4);

		return id[tmp[0]][tmp[1]][tmp[2]][tmp[3]];

	}



	int insert(int k) {

		assert(!x);

		tmp[0] = k;

		tmp[1] = y;

		tmp[2] = z;

		tmp[3] = t;

		sort(tmp, tmp + 4);

		return id[tmp[0]][tmp[1]][tmp[2]][tmp[3]];

	}



	void print() {

		printf("(%d %d %d %d)\n", x, y, z, t);

	}

} B[M];



void prep() {

	e = 0;

	for (int xx = 0; xx < K; xx ++) for (int yy = xx; yy < K; yy ++) for (int zz = yy; zz < K; zz ++) for (int tt = zz; tt < K; tt ++) {

		e ++;

		B[e].x = xx;

		B[e].y = yy;

		B[e].z = zz;

		B[e].t = tt;

		id[xx][yy][zz][tt] = e;

	}

}



#define N 2020



int f[N][K][M];



int n, a[N], b[N];



int main() {

	//freopen("r.in", "r", stdin);

	prep();

	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) scanf("%d %d", &a[i], &b[i]);

	for (int i = 1; i <= e; i ++) {

		for (int w = 1; w < K; w ++) {

			if (i == 1) {

				f[n+1][w][1] = 0;

				continue;

			}

			int rlt = 0;

			int tmp = INF;

			for (int k = 3; k >= 0 && B[i].ftf[k]; k --) {

				int to = B[i].ftf[k];

				int j = B[i].erase(k);

				tmp = min(tmp, abs(w - to) + f[n+1][to][j]);

			}

			f[n+1][w][i] = tmp;

		}

	}



	for (int m = n; m >= 1; m --) {

		for (int i = 1; i <= e; i ++) {

			for (int w = 1; w < K; w ++) {//bool flag = 0;if (m == 5 && w == 1 && i == 386) flag = 1;

				int tmp = INF;

				for (int k = 3; k >= 0 && B[i].ftf[k]; k --) {

					int to = B[i].ftf[k];

					int j = B[i].erase(k);

					tmp = min(tmp, abs(w - to) + f[m][to][j]);//if (flag) printf("f[%d][%d][%d] = %d\n", m, to, j, f[m][to][j]);

				}

				if (!B[i].x) {

					int to = a[m];

					int j = B[i].insert(b[m]);

					tmp = min(tmp, abs(w - to) + f[m+1][to][j]);//if (flag) printf("f[%d][%d][%d] = %d\n", m + 1, to, j, f[m+1][to][j]);

				}

				f[m][w][i] = tmp;

			}

		}

	}

	printf("%d\n", 2 * n + f[1][1][1]);



	return 0;

}