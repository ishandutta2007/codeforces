#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 2000010
#define MAXNH 1000010

int n, nq;
int inp[MAXN];
typedef long long LL;
LL sum[MAXN];
LL b;
int jmp[22][MAXNH];
int cur[2][MAXNH];

int find(int i) {
	int L = 1, R = n+1, M;
	while (R > L+1) {
		M = (L+R)/2;
		if (sum[i+M] - sum[i] <= b) L = M;
		else R = M;
	}
	return L;
}

int vis[MAXN], nvi[MAXN];
int main() {
	scanf("%d%d", &n, &nq);
	for (int i=0; i<n; i++) {
		scanf("%d", &inp[i]);
		inp[i+n] = inp[i];
	}
	for (int i=0; i<2*n; i++) sum[i+1] = sum[i] + inp[i];
	for (int q=0; q<nq; q++) {
		cin >> b;
		
		int r = find(0)+1;
		for (int i=0; i<n; i++) {
			r = max(r-1, 1);
			while (r < n && sum[i+r+1] - sum[i] <= b) r++;
			jmp[0][i] = r;
			jmp[0][i+n] = jmp[0][i];
			//printf("%d ", jmp[0][i]);
		}

		memset(vis, 0, sizeof(vis));
		nvi[0] = vis[0] = 0;
		int ans = 0;
		int cur = 0;
		while (cur < n) {
			cur = cur + jmp[0][cur];
			ans++;
			nvi[ans] = vis[ans] = cur;
		}
		int fnd = 0;
		nvi[ans+1] = 2*n;
		for (int i=1; i<=vis[1]; i++) {
			nvi[0] = i;
			int chk = 0;
			for (int j=0; j<ans; j++) {
				if (nvi[j+1] == nvi[j] + jmp[0][nvi[j]]) break;
				nvi[j+1] = nvi[j] + jmp[0][nvi[j]];
				chk = j+1;
			}
			//for (int j=0; j<=ans; j++) printf("%d ", nvi[j]);
			//puts("");
			if (nvi[ans-1] >= i + n) {fnd = 1; break;}
			for (int j=0; j<=chk; j++) {
				if (nvi[j] >= vis[j+1]) {
					goto OUT;
				}
			}
		}
		OUT:;


		/*
		//int ans = jmp[0][n-1];
		
		//puts("");
		for (int i=1; i<=20; i++) {
			for (int j=0; j<n; j++) {
				jmp[i][j] = min(n, jmp[i-1][j] + jmp[i-1][j+jmp[i-1][j]]);
				jmp[i][j+n] = jmp[i][j];
				//printf("%d ", jmp[i][j]);
			}
			//puts("");
		}
		memset(cur, 0, sizeof(cur));
		int ans = 0;
		int bj = 0;
		for (int i=20; i>=0; i--) {
			for (int j=0; j<n; j++) {
				cur[1-bj][j] = min(n, cur[bj][j] + jmp[i][j+cur[bj][j]]);
				if (cur[1-bj][j] >= n) goto NEXT;
			}
			bj = 1-bj;
			ans |= 1<<i;
			NEXT:;
		}
		*/
		
		printf("%d\n", ans-fnd);
	}
	return 0;
}