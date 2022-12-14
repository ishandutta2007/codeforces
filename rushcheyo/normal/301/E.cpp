#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=105,P=1000000007;
void inc(int &a,int b){a+=b;if(a>=P)a-=P;}
int n,m,k,ans,C[N][N],dp[2][N][N][N];
vector<int>tr[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=k;i++)
		for(int j=C[i][0]=1;j<=i;j++)C[i][j]=min(k+1,C[i-1][j]+C[i-1][j-1]);
	for(int a=1;a<=k;a++)
		for(int b=1;b<=k;b++)
			if(a+b-1<=k&&C[a+b-1][b]<=k)
				tr[a].push_back(b);
	n>>=1;
	for(int a=1;a<=n;a++)dp[1][1][a][a]=1,inc(ans,m-1);
	int lst=0,now=1;
	for(int i=2;i<=m;i++){
		lst^=1,now^=1;
		for(int j=1;j<=k;j++)
			for(int a=1;a<=n;a++)
				for(int b=a+i-2;b<=n;b++){
					if(!dp[lst][j][a][b])continue;
					for(auto c:tr[a])
						if(j*C[a+c-1][c]<=k&&b+c<=n)
							inc(dp[now][j*C[a+c-1][c]][c][b+c],dp[lst][j][a][b]);
				}
		for(int j=1;j<=k;j++)
			for(int a=1;a<=n;a++)
				for(int b=a+i-1;b<=n;b++){
					dp[lst][j][a][b]=0;
					inc(ans,1ll*dp[now][j][a][b]*(m-i)%P);
				}
	}
	printf("%d\n",ans);
	return 0;
}