#include <bits/stdc++.h>
using namespace std;
const int N=502;
int n,m,q;
char s[N][N];
int UL[N][N],UR[N][N],DL[N][N],DR[N][N];
int sum[N][N][N];

int U[N][N],L[N][N],D[N][N],R[N][N],f[N][N];
void tackle(char c) {
	memset(U,0,sizeof(U));
	memset(L,0,sizeof(L));
	memset(D,0,sizeof(D));
	memset(R,0,sizeof(R));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==c) {
				U[i][j]=U[i-1][j]+1;
				L[i][j]=L[i][j-1]+1;
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(s[i][j]==c){
				D[i][j]=D[i+1][j]+1;
				R[i][j]=R[i][j+1]+1;
			}
		}
	}
}

int hav(int id,int r1,int r2,int c1,int c2) {
	//printf("query %d %d %d %d %d\n", id,r1,r2,c1,c2);
	//printf("sum %d\n", sum[id][r2][c2]);
	return (sum[id][r2][c2] - sum[id][r1-1][c2] - sum[id][r2][c1-1] + sum[id][r1-1][c1-1]) > 0;
}

int main() {
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}

	tackle('R');
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='R'){
				UL[i][j]=min(UL[i-1][j-1]+1, min(L[i][j],U[i][j]));
			}
		}
	}

	tackle('G');
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(s[i][j]=='G'){
				UR[i][j]=min(UR[i-1][j+1]+1, min(R[i][j],U[i][j]));
			}
		}
	}

	tackle('Y');
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='Y'){
				DL[i][j]=min(DL[i+1][j-1]+1, min(L[i][j],D[i][j]));
			}
		}
	}

	tackle('B');
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(s[i][j]=='B'){
				DR[i][j]=min(DR[i+1][j+1]+1, min(R[i][j],D[i][j]));
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j] = min(min(UL[i][j],UR[i][j+1]),min(DL[i+1][j],DR[i+1][j+1]));
			//printf("%d",f[i][j]);
		}
		//printf("\n");
	}
	for(int i=1;i<=250;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++)if(f[j][k]>=i)sum[i][j][k]=1;
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++)sum[i][j][k]+=sum[i][j-1][k]+sum[i][j][k-1]-sum[i][j-1][k-1];
		}
	}
	//printf("# %d\n", sum[2][5][5]);

	for (int i=1;i<=q;i++){
		int r1,c1,r2,c2;
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		int x=min(r2-r1+1,c2-c1+1)/2;
		int ans=0;
		for(int i=x;i>=1;i--){
			//printf("i=%d\n", i);
			int R1=r1+i-1, R2=r2-i;
			int C1=c1+i-1, C2=c2-i;
			//printf("[%d,%d] [%d,%d]\n", R1,R2,C1,C2);
			if(hav(i,R1,R2,C1,C2)) {
				ans=i; break;
			}
		}
		printf("%d\n", 4*ans*ans);
	}
}