#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define N 1010
vector <int> v[N];

bool cmp(int i, int j) { return i > j; }

int n, T;
int L[N];
int f[N][N];
int g[N];
int ans;

int main() {
	//freopen("F.in","r",stdin);
	scanf("%d%d", &n, &T);
	for(int i = 0; i < n; i ++) {
		int t, q;
		scanf("%d %d", &t, &q); v[t].push_back(q);
	}
	for(int i = 1; i <= T; i ++) if(v[i].size() > 1) sort(v[i].begin(), v[i].end(), cmp);
	int x = 1;
	for(int i = T; i; i --) {
		L[i] = x;
		x *= 2;
		if(x > n) x = n;
	}
	for(int i = 1; i <= T; i ++) {
		int k = v[i].size();
		for(int j = 0; j < k; j ++) {
			g[j + 1] = g[j] + v[i][j];
		}
		for(int j = 1; j <= L[i]; j ++) {
			int jj;
			for(jj = 0; jj <= j && jj <= k; jj ++) {
				int tt = (j - jj) * 2;
				if(tt > L[i-1]) tt = L[i-1];
				int tp = g[jj] + f[i-1][tt];
				if(f[i][j] < tp) f[i][j] = tp;
			}
			for(int kk = j; kk >= jj; kk --) {
				int tt = (j - kk) * 2, tp;
				if(tt >= L[i-1]) {
					tt = L[i-1];
					tp = g[k] + f[i-1][tt];
					if(f[i][j] < tp) f[i][j] = tp;
					break;
				}
				tp = g[k] + f[i-1][tt];
				if(f[i][j] < tp) f[i][j] = tp;
			}
		}
	}
	printf("%d\n", f[T][1]);
	return 0;
}