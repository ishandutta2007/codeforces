/*
Let's define f[i][j] as we have got (i,j) and the last step is moving right and the next move is to move down,
g[i][j] as we have got (i,j) and the last step is moving down and the next move is to move right.
It's easy to prove that all the stones on the down(or the right) of (i,j) have not been pushed.
Thus,f[i][j]=sigma(g[i+t][j]),g[i][j]=sigma(f[i][j+t]).(if t is possible)
We can find the answer i:from n to 1,j:from m to 1.
If n == 1&&m == 1  then puts("1");return 0;
Otherwise,f[n][m]=g[n][m]=1,then work.
*/
#include <cstdio>
#define Maxn 2000
#define Mod 1000000007
char s[Maxn+5][Maxn+5];
int line[Maxn+5][Maxn+5],row[Maxn+5][Maxn+5];
int f[Maxn+5][Maxn+5],g[Maxn+5][Maxn+5];
int sum_f[Maxn+5][Maxn+5],sum_g[Maxn+5][Maxn+5];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=m;j>0;j--){
			row[i][j]=row[i][j+1];
			if(s[i][j+1]=='R'){
				row[i][j]++;
			}
		}
	}
	if(n==1&&m==1){
		puts("1");
		return 0;
	}
	if(s[n][m]=='R'){
		puts("0");
		return 0;
	}
	for(int j=1;j<=m;j++){
		for(int i=n;i>0;i--){
			line[i][j]=line[i+1][j];
			if(s[i+1][j]=='R'){
				line[i][j]++;
			}
		}
	}
	int t;
	for(int i=n;i>0;i--){
		for(int j=m;j>0;j--){
			if(i==n&&j==m){
				f[i][j]=g[i][j]=1;
				sum_f[i][j]=sum_g[i][j]=1;
				continue;
			}
			t=n-i-line[i][j]+1;
			f[i][j]=sum_g[i+1][j]-sum_g[i+t][j];
			f[i][j]=(f[i][j]+Mod)%Mod;
			t=m-j-row[i][j]+1;
			g[i][j]=sum_f[i][j+1]-sum_f[i][j+t];
			g[i][j]=(g[i][j]+Mod)%Mod;
			sum_g[i][j]=(sum_g[i+1][j]+g[i][j])%Mod;
			sum_f[i][j]=(sum_f[i][j+1]+f[i][j])%Mod;
		}
	}
	printf("%d\n",(f[1][1]+g[1][1])%Mod);
	return 0;
}