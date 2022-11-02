#include <bits/stdc++.h>
using namespace std;
#define N 1005

int s[N], t[N], rmn[N], rmx[N], cmn[N], cmx[N], ans, a[N][N];

int main(){
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++) rmn[i] = m + 1;
	for(j = 1; j <= m; j++) cmn[j] = n + 1;
	for(i = 1; i <= n; i++) for(j = 1; j <= m; j++) scanf("%d", &a[i][j]);
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			if(a[i][j]){
				s[i]++; t[j]++;
				rmn[i] = min(rmn[i], j);
				rmx[i] = max(rmx[i], j);
				cmn[j] = min(cmn[j], i);
				cmx[j] = max(cmx[j], i);
			}
		}
	}
	for(i = 1; i <= n; i++){
		ans += m - rmn[i] - s[i] + 1;
		ans += rmx[i] - s[i];
	}
	for(j = 1; j <= m; j++){
		ans += n - cmn[j] - t[j] + 1;
		ans += cmx[j] - t[j];
	}
	printf("%d", ans);
}