#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 110;

int t,n,m,c[N][N];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		c[1][1] = 1;
		for(int i=1;i <= n;i++){
			for(int j=1;j <= m;j++)
				printf("%c",c[i][j] ? 'W' : 'B');
			puts("");
		}
	}
}