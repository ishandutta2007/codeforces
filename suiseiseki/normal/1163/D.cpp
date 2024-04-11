#include <cstdio>
#include <cstring>
#define REP(i,a,n) for(int i=a;i<=n;++i)
const int N = 1310;
char s1[N], s2[55], s3[55];
int f2[55], f3[55];
void getFail(char *s, int *f) {
	int m = strlen(s);
	f[0]=f[1]=0;
	REP(i,1,m-1) {
		int j=f[i];
		while (j&&s[i]!=s[j]) j=f[j];
		if (s[i]==s[j]) ++j;
		f[i+1] = j;
	}
	REP(i,1,m-1) while (f[i]&&s[i]==s[f[i]]) f[i]=f[f[i]];
}
int dp[N][55][55];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%s%s%s",s1+1,s2,s3);
	getFail(s2,f2),getFail(s3,f3);
	int n1=strlen(s1+1),n2=strlen(s2), n3 = strlen(s3);
	memset(dp,0xcf,sizeof dp);
	int INF = dp[0][0][0], ans = INF;
	dp[0][0][0] = 0;
	REP(i,1,n1) REP(j,0,n2) REP(k,0,n3) if (dp[i-1][j][k]!=INF) {
		int L='a',R='z';
		if (s1[i]!='*') L=R=s1[i];
		REP(c,L,R) {
			int p2=j,p3=k;
			while (p2&&s2[p2]!=c) p2=f2[p2];
			if (s2[p2]==c) ++p2;
			while (p3&&s3[p3]!=c) p3=f3[p3];
			if (s3[p3]==c) ++p3;
			dp[i][p2][p3] = mx(dp[i][p2][p3], dp[i-1][j][k]+(p2==n2)-(p3==n3));
			if (i==n1) ans = mx(ans, dp[i][p2][p3]);
		}
	}
	printf("%d\n", ans);
	return 0;
}