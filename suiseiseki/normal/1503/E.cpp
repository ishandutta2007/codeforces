#include<bits/stdc++.h>
using namespace std;
const int Maxn=2021;
const int Mod=998244353;
int C[Maxn<<1|5][Maxn<<1|5];
int w[Maxn+5][Maxn+5];
int sum[Maxn+5][Maxn+5];
int ans;
void init(){
	C[0][0]=1;
	for(int i=1;i<=(Maxn<<1);i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
		}
	}
}
void solve(int n,int m,int k){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int t_1=C[i-1+m-j][m-j],t_2=C[i+j-1][j-1];
			w[i][j]=1ll*t_1*t_2%Mod;
			sum[i][j]=(sum[i][j-1]+w[i][j])%Mod;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			ans=(ans+1ll*w[i][j]*sum[n-i][m-j])%Mod;
			if(k==1){
				ans=(ans-1ll*w[i][j]*w[n-i][m-j]%Mod+Mod)%Mod;
			}
		}
	}
}
int main(){
	init();
	int n,m;
	scanf("%d%d",&n,&m);
	solve(n,m,1);
	solve(m,n,0);
	ans=(ans<<1)%Mod;
	printf("%d\n",ans);
	return 0;
}