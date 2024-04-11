#include<cstdio>
#include<algorithm>
#include<string>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 3005, MY = 10005, INF = 1000000000;

P d[MX];
int nd[MX], dn[MX];
struct qu{int t, x, y, z;};
qu qd[305];
int dp[MY], pd[MY];

int main(){
	int n, k, a, b = -1, ans = 0;
	scanf("%d%d",&n,&k);
	
	rrep(i,n){
		scanf("%d",&a);
		if(!a || (i>k&&b!=a)) break;
		ans++;
		b = a;
	}
	
	printf("%d\n",ans);
	
	return 0;
}