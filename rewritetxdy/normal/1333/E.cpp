#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 510;

int n,c[N][N],x;

int main()
{
	scanf("%d",&n);
	if(n <= 2){
		puts("-1");
		return 0;
	}
	x=n*n-9;
	c[1][1] = x+9 , c[1][2] = x+4 , c[1][3] = x+5;
	c[2][1] = x+1 , c[2][2] = x+2 , c[2][3] = x+3;
	c[3][1] = x+7 , c[3][2] = x+8 , c[3][3] = x+6;
	for(int k=4;k <= n;k++){
		for(int i=1;i <= k;i++) c[k][i] = x--;
		for(int i=k-1;i >= 1;i--) c[i][k] = x--;
		if(++k <= n){
			for(int i=1;i <= k;i++) c[i][k] = x--;
			for(int i=k-1;i >= 1;i--) c[k][i] = x--;
		}
	}
	for(int i=1;i <= n;i++){
		for(int j=1;j <= n;j++)
			printf("%d ",c[i][j]);
		puts("");
	}
}