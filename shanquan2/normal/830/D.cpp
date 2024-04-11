#include<bits/stdc++.h>
using namespace std;

const int M=1000000007;
int n,f[405][405];
int main(){
	scanf("%d",&n);
	f[1][0]=f[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=n;j++)for(int k=0;k<=n;k++){
			int t=1ll*f[i-1][j]*f[i-1][k]%M;
			if(j+k+1<=n)(f[i][j+k+1]+=t)%=M;
			if(j+k<=n){
				(f[i][j+k]+=t)%=M;
				(f[i][j+k]+=2ll*t*j%M)%=M;
				(f[i][j+k]+=2ll*t*k%M)%=M;
			}
			if(j+k-1<=n){
				(f[i][j+k-1]+=1ll*t*(j+k)*(j+k-1)%M)%=M;
			}
		}
	}
	printf("%d\n",f[n][1]);
	return 0;
}