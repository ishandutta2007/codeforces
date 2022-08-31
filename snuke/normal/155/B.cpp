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
const int MX = 1005, INF = 100000000;

P c[MX];

int main(){
	int n, x = 1, ans = 0;
	scanf("%d",&n);
	
	rep(i,n) scanf("%d%d",&c[i].se,&c[i].fi);
	sort(c,c+n);
	
	int j = n-1;
	while(x && j>=0){
		x += c[j].fi;
		ans += c[j].se;
		x--; j--;
	}
	
	printf("%d\n",ans);
	
	return 0;
}