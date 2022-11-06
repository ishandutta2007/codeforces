//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 55;

int n, a[N][N], deg[N]; 

int main() {
	scanf("%d", &n);
	int m = n * (n - 1) / 2 - 1;
	rep(i, 1, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		++deg[x];
		if(x < y) swap(x, y);
		a[x][y] = 1;
	}
	rep(i, 1, n) {
		rep(j, 1, i-1) {
			if(!a[i][j]) {
				if(deg[i] < deg[j]) printf("%d %d\n", j, i);
				else printf("%d %d\n", i, j);
			}
		}
	}
	return 0;
}