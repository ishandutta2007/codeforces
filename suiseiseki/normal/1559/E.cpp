#include <bits/stdc++.h>
const int Maxn=101000;
const int Mod=998244353;
int n,m;
int f[55][Maxn+5];
int g[Maxn+5];
int l[55],r[55];
int get(int i,int j){
	return j<0?0:f[i][j];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	for(int d=m;d>0;d--){
		int t=m/d;
		for(int j=0;j<=t;j++){
			f[0][j]=1;
		}
		for(int j=1;j<=n;j++){
			int L=(l[j]+d-1)/d,R=r[j]/d;
			for(int k=0;k<=t;k++){
				f[j][k]=(0ll+f[j][k-1]+get(j-1,k-L)-get(j-1,k-R-1)+Mod)%Mod;
			}
		}
		g[d]=f[n][t];
		for(int j=2;j<=t;j++){
			g[d]=(g[d]-g[j*d]+Mod)%Mod;
		}
	}
	printf("%d\n",g[1]);
	return 0;
}


/**/