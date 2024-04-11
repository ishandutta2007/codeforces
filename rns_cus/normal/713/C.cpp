#include <bits/stdc++.h>
using namespace std;
#define M 3010

typedef long long LL;

LL res[M][M];
int a[M];
int b[M];

int main(){
	//freopen("in.txt", "r", stdin);

	int n;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
		scanf("%d", a + i);
		a[i] -= i;
		b[i] = a[i];
    }

	sort(b + 1, b + n + 1);
    int m = unique(b + 1, b + n + 1) - b - 1;


    res[0][0] = 0;

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
            res[i][j] = res[i - 1][j] + abs(b[j] - a[i]);
			if(j > 1) res[i][j] = min(res[i][j], res[i][j - 1]);
    	}
    }

    LL r = 1e18;
    for(int i = 1; i <= m; i++) r = min(r, res[n][i]);

    printf("%I64d\n", r);

	return 0;
}