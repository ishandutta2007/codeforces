#include <cstdio>
#include <cstring>
const int Maxn=100;
int f[Maxn+5][Maxn+5][Maxn+5][2];
int a[Maxn+5];
int n;
int num_1,num_2;
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d",&n);
	num_1=((n+1)>>1);
	num_2=(n>>1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>0){
			if(a[i]&1){
				num_1--;
			}
			else{
				num_2--;
			}
		}
	}
	memset(f,0x3f,sizeof f);
	f[0][num_1][num_2][0]=f[0][num_1][num_2][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=num_1;j++){
			for(int k=0;k<=num_2;k++){
				if(a[i]>0){
					if(a[i]&1){
						f[i][j][k][1]=mn(f[i-1][j][k][1],f[i-1][j][k][0]+1);
					}
					else{
						f[i][j][k][0]=mn(f[i-1][j][k][0],f[i-1][j][k][1]+1);
					}
				}
				else{
					f[i][j][k][1]=mn(f[i-1][j+1][k][1],f[i-1][j+1][k][0]+1);
					f[i][j][k][0]=mn(f[i-1][j][k+1][0],f[i-1][j][k+1][1]+1);
				}
			}
		}
	}
	printf("%d\n",mn(f[n][0][0][0],f[n][0][0][1]));
	return 0;
}