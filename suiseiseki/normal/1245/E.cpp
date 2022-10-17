#include <cstdio>
#define Inf 1e12
int n=10;
int mp[15][15];
double f[15][15][2];
double mn(double a,double b){
	return a<b?a:b;
}
double lst(int i,int j,int k){
	if(i&1){
		j-=k;
		if(j<1){
			i--;
			j=1-j;
		}
		return mn(f[i][j][0],f[i][j][1]);
	}
	else{
		j+=k;
		if(j>n){
			i--;
			j=n-(j-n-1);
		}
		return mn(f[i][j][0],f[i][j][1]);
	}
}
int main(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&mp[i][j]);
		}
	}
	f[1][1][1]=f[1][2][1]=f[1][3][1]=f[1][4][1]=f[1][5][1]=f[1][6][1]=Inf;
	f[1][1][0]=0.0;
	f[1][2][0]=f[1][3][0]=f[1][4][0]=f[1][5][0]=f[1][6][0]=6.0;
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				if(i==1&&j<=6){
					continue;
				}
				for(int k=1;k<=6;k++){
					f[i][j][0]+=(lst(i,j,k)+1.0)/6.0;
				}
				if(mp[i][j]){
					f[i][j][1]=f[i-mp[i][j]][j][0];
				}
				else{
					f[i][j][1]=Inf;
				}
			}
		}
		else{
			for(int j=n;j>0;j--){
				for(int k=1;k<=6;k++){
					f[i][j][0]+=(lst(i,j,k)+1.0)/6.0;
				}
				if(mp[i][j]){
					f[i][j][1]=f[i-mp[i][j]][j][0];
				}
				else{
					f[i][j][1]=Inf;
				}
			}
		}
	}
	printf("%.12lf\n",f[n][1][0]);
	return 0;
}