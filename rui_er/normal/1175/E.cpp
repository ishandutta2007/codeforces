//By: Luogu@rui_er(122461)..
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;

int n, m, l[N], r[N], qwq[N][22], ma;

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) {
		scanf("%d%d", &l[i], &r[i]); 
		qwq[l[i]][0] = max(qwq[l[i]][0], r[i]);
		ma = max(ma, r[i]);
	}
	for(int i=1;i<=ma;i++) qwq[i][0] = max(qwq[i][0], qwq[i-1][0]);
	for(int j=1;j<=21;j++) for(int i=0;i<=ma;i++) qwq[i][j] = max(qwq[i][j-1], qwq[qwq[i][j-1]][j-1]);
	while(m--) {
		int L, R, ans = 0;
		scanf("%d%d", &L, &R);
		int i = L;
		for(int j=21;j>=0;j--) {
//			printf("%d %d %d\n", i, j, qwq[i][j]);
//			if(!i) {ans = -1; break;}
			if(qwq[i][j] && qwq[i][j] < R) {
				i = qwq[i][j];
				ans += (1 << j);
			}
		}
		printf("%d\n", (qwq[i][0]>=R)?(ans+1):-1);
	}
	return 0;
}