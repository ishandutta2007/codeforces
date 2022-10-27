#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[300000+10]; 
const int N = 1002; 
int f[N][4] = {0}, temp[4];
int solve(int x,int y,int z){
	memset(f, 0, sizeof(f));
	for (int i = 1; i < N; i ++) {
		for (int j = 1; j <= 3; j ++) {
			bool vis[100] = {0};
			vis[ f[max(i-x,0)][1] ] = 1;
			if (j != 2) vis[ f[max(i-y,0)][2] ] = 1;
			if (j != 3) vis[ f[max(i-z,0)][3] ] = 1;
			for (int k = 0;; k ++) {
				if (vis[k] == 0) {
					f[i][j] = k; break;
				}
			}
		}
		//printf("i=%d, val = %d\n", i,f[i][1]);
	}
	for (int x = 1; x <= 3; x ++) {
		for (int T = 1; T <= 100; T ++) {
			bool flag = 1;
			for (int j = N-1; j >= N-4*T; j --) {
				if (f[j][1] != f[j-T][1]) {
					flag = 0; break;
				}
			}
			if (flag) {
				temp[x] = T;
				break;
			}
		}
	}
}
int sg(LL x, int k) {
	if (x < N-1) return f[x][k];
	for (int i = N-1; i >=0; i --) if (i % temp[k] == x % temp[k]) return f[i][k];
}
int main() {
	//cout << solve(5,4,5);
	int t; scanf("%d", &t);
	while (t --) {
		int n,x,y,z; scanf("%d%d%d%d",&n,&x,&y,&z);
		solve(x, y, z);
		LL ans = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%lld", &a[i]);
			ans ^= sg(a[i], 1);
		}
		int res = 0;
		for (int i = 1; i <= n; i ++) {
			ans ^= sg(a[i], 1);
			bool flag = 0;
			if ( (sg(max(a[i] - x, 0LL), 1) ^ ans) == 0 ) res++;
			if ( (sg(max(a[i] - y, 0LL), 2) ^ ans) == 0 ) res++;
			if ( (sg(max(a[i] - z, 0LL), 3) ^ ans) == 0 ) res++;
			ans ^= sg(a[i], 1);
		}
		printf("%d\n", res);
	}	
}