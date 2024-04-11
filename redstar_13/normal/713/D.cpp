#include <bits/stdc++.h>

using namespace std;
#define NN 1010
int a[NN][NN];
int dp[NN][NN];
int f[NN][NN][10][10];

int calc(int x1,int y1,int x2,int y2){
	int p=31-__builtin_clz(x2-x1+1);
	int q=31-__builtin_clz(y2-y1+1);
	return max(max(f[x1][y1][p][q],f[x2-(1<<p)+1][y1][p][q]),max(f[x1][y2-(1<<q)+1][p][q],f[x2-(1<<p)+1][y2-(1<<q)+1][p][q]));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]) dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
		}
	}
	for(int p=0;p<10;p++){
		for(int q=0;q<10;q++){
			for(int i=1;i+(1<<p)-1<=n;i++){
				for(int j=1;j+(1<<q)-1<=m;j++){
					if(p==0&&q==0){
						f[i][j][p][q]=dp[i][j];
					}
					else{
						if(p){
							f[i][j][p][q]=max(f[i][j][p-1][q],f[i+(1<<(p-1))][j][p-1][q]);
						}
						else if(q){
							f[i][j][p][q]=max(f[i][j][p][q-1],f[i][j+(1<<(q-1))][p][q-1]);
						}
					}	
				}
			}
		}
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int st=0,ed=min(y2-y1+1,x2-x1+1)+1;
		while(st+1<ed){
			int x=(st+ed)>>1;
			if(calc(x1+x-1,y1+x-1,x2,y2)>=x) st=x;
			else ed=x;
		}
		printf("%d\n",st);
	}
    return 0;
}