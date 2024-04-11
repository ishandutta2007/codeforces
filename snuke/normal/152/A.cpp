#include<cstdio>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<P,int> Q;

const int MX = 105, INF = 100000000;

int a[MX][MX];
bool b[MX];

int main(){
	char x;
	int n, m;
	scanf("%d%d",&n,&m);
	
	rep(i,n){
		rep(j,m){ scanf(" %c",&x); a[i][j] = x-'0';}
	}
	
	rep(i,m){
		int c = 0;
		rep(j,n) c = max(c,a[j][i]);
		rep(j,n) if(a[j][i] == c) b[j] = true;
	}
	
	int ans = 0;
	rep(i,n) if(b[i]) ans++;
	printf("%d\n",ans);
	
	return 0;
}