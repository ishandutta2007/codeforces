#include<cstdio>
#include<queue>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
const int MX = 100005, INF = 100000000;

char s[MX];
bool f[26][26];
int dp[26];

int main(){
	char a, b;
	int n, ans = INF, x;
	scanf("%s%d",s,&n);
	
	rep(i,n){
		scanf(" %c%c",&a,&b);
		a -= 'a'; b -= 'a';
		f[a][b] = true;
		f[b][a] = true;
	}
	
	rep(i,26) dp[i] = INF;
	dp[s[0]-'a'] = 0;
	for(int i = 1; s[i] != '\0'; i++){
		a = s[i]-'a'; x = dp[a];
		rep(j,26){
			if(!f[j][a]) dp[a] = min(dp[a],dp[j]);
		}
		rep(j,26) if(j!=a) dp[j]++;
		
		if(!f[a][a]) dp[a] = min(dp[a],x);
		dp[a] = min(dp[a],i);
	}
	
	rep(i,26) ans = min(ans,dp[i]);
	printf("%d\n",ans);
	
	return 0;
}