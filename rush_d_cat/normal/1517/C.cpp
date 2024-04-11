#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 10;
int n, a[N][N], p[N];
bool in(int x, int y) {
	return x>=1 && x<=n && y>=1 && y<=n;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> p[i], a[i][i] = p[i];
	for (int i = n; i >= 1; i --) {
		int x = i, y = i;
		//printf("i = %d\n", i);
		for (int j = 1; j < p[i]; j ++) {
			if (in(x+1, y) && a[x+1][y] == 0) {
				x ++; a[x][y] = p[i];
				//printf("%d %d\n", x, y);
			} else if (in(x, y-1) && a[x][y-1] == 0) {
				y --; a[x][y] = p[i];
				//printf("%d %d\n", x, y);
			} else {
				assert(0);
			}
		} 
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= i; j ++) {
			cout << a[i][j] << " \n"[j==i];
		}
	}
}