#include<cstdio>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef pair<int,int> P;
typedef long long int ll;

const int MX = 50000, INF = 100000000;
const double eps = 1e-10;

int c[100][101], v[101], dp[2][10001];

int main(){
	int n, m, o, p = 0, q = 1;
	
	scanf("%d%d",&n,&m);
	
	rep(i,n){
		scanf("%d",&o);
		rrep(j,o) scanf("%d",&v[j]);
		rrep(j,o) v[j] += v[j-1];
		
		rrep(j,o){
			for(int k = 0; k <= j; k++){
				c[i][j] = max(c[i][j], v[k]+v[o]-v[o-(j-k)]);
			}
		}
		
		for(int k = 0; k <= m; k++) dp[p][k] = 0;
		for(int j = 0; j <= o; j++){
			for(int k = j; k <= m; k++){
				dp[p][k] = max(dp[p][k],dp[q][k-j]+c[i][j]);
			}
		}
		
		swap(p,q);
	}
	
	int ans = 0;
	for(int k = 0; k <= m; k++) ans = max(ans,dp[q][k]);
	printf("%d\n",ans);
	
	return 0;
}