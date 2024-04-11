#include <cstdio>
int _n,n,p,a[32],pos[32],b[32],tot;
bool dp[32][32][50005];
int append(int i,int j) {
	if (j<=9) return (i*10+j)%p;
	else return (i*100+j)%p;
}
void print(int i,int j,int k) {
	if (i==0) return;
	for (int l=0;l<p;l++)
		if (append(l,a[i])==k&&dp[i-1][j^a[i]][l]) {
			print(i-1,j^a[i],l);
			b[++tot]=pos[i];
			return;
		}
	print(i-1,j,k);
}
int main() {
	scanf("%d%d",&_n,&p);
	for (int i=1,x;i<=_n;i++) {
		scanf("%d",&x);
		if (x<=31) a[++n]=x,pos[n]=i;
	}
	dp[0][0][0]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<32;j++)
			for (int k=0;k<p;k++)
				if (dp[i][j][k]) {
					dp[i+1][j][k]=1;
					dp[i+1][j^a[i+1]][append(k,a[i+1])]=1;
				}
	print(n,0,0);
	if (tot==0) puts("No");
	else {
		printf("Yes\n%d\n",tot);
		for (int i=1;i<=tot;i++) printf("%d%c",b[i]," \n"[i==tot]);
	}
}