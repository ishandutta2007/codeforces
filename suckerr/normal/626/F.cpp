#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 200 + 2;
const int K = 1000 + 2;
const int MOD = 1e9 + 7;

int n, k;
int f[N][N][K];
int task[N];

void update(int i, int j, int p, int v) {
	if (p > k) {
		return ;
	} else {
		if ((f[i][j][p] += v) >= MOD) {
			f[i][j][p] -= MOD;
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &task[i]);
	}
	sort(task, task + n);
	task[n] = task[n - 1];

	f[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		int delta = task[i + 1] - task[i];
		for (int j = 0; j <= i; j++) {
			for (int p = 0; p <= k; p++) {
				int v = f[i][j][p];
				if (v == 0) {
					continue;
				} else {
					update(i + 1, j, p + j * delta, v);
					update(i + 1, j + 1, p + (j + 1) * delta, v);
					if (j) {
						update(i + 1, j - 1, p + (j - 1) * delta, 1LL * v * j % MOD);
						update(i + 1, j, p + j * delta, 1LL * v * j % MOD);
					}
				}
			}
		}
	}


	int answer = 0;
	for (int i = 0; i <= k; i++) {
		answer += f[n][0][i];
		if (answer >= MOD) {
			answer -= MOD;
		}
	}
	cout << answer << endl;
	return 0;
}