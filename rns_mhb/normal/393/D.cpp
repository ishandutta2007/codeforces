#include <bits/stdc++.h>
using namespace std;

int n, t[4][4];
long long ans[4][4][50];

void calc(){
	for(int k = 1; k < 50; k ++){
		for(int i = 0; i < 3; i ++){
			for(int j = 0; j < 3; j ++){
				if(i == j)	continue;
				if(k == 1)	ans[i][j][k] = min(t[i][j], t[i][3 - i - j] + t[3 - i - j][j]);
				else	ans[i][j][k] = min(ans[i][3 - i - j][k - 1] + t[i][j] + ans[3 - i - j][j][k - 1], 2 * ans[i][j][k - 1] + t[i][3 - i - j] + ans[j][i][k - 1] + t[3 - i - j][j]);
			}
		}
	}
}

int main(){
	for(int i = 0; i < 3; i ++)	for(int j = 0; j < 3; j ++)	scanf("%d", &t[i][j]);
	scanf("%d", &n);
	calc();
	printf("%I64d", ans[0][2][n]);
}