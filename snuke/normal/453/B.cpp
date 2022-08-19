#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<int,P> Q;
typedef pair<P,P> R;
typedef vector<int> vi;

const int MX = 105, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int p[] = {2,3,5,7,11,13,17,19,23,29};
int q[] = {31,37,41,43,47,53,59,61,67,71};

int a[MX];
R dp[MX][1<<10][10];
int d[MX];
int y[MX];

int main(){
	int n = 10;
	cin >> n;
	rep(i,n) cin >> a[i];
	rep(i,n+1)rep(j,1<<10)rep(k,10) dp[i][j][k] = R(P(INF,0),P(0,0));
	rrep(i,60) {
		int x = i;
		int f = 0;
		rep(j,10) {
			while (x%p[j] == 0) {
				x /= p[j];
				f |= 1<<j;
			}
		}
		if (x == 1) {
			d[i] = f;
		} else d[i] = -1;
	}

	dp[0][0][0] = R(P(0,0),P(0,0));
	rep(i,n)rep(j,1<<10)rep(k,9){
		rrep(l,60) {
			int f = d[l];
			if (f == -1) continue;
			if (f&j) continue;
			R dpx = dp[i][j][k];
			dpx.fi.fi += abs(a[i]-l);
			dpx.fi.se = l;
			dpx.se = P(j,k);
			mins(dp[i+1][j|f][k], dpx);
		}
		{
			R dpx = dp[i][j][k];
			dpx.fi.fi += (30-a[i]);
			dpx.fi.se = q[k];
			dpx.se = P(j,k);
			mins(dp[i+1][j][k+1], dpx);
		}
	}

	Q ans = Q(INF,P(0,0));
	rep(j,1<<10)rep(k,9){
		int x = dp[n][j][k].fi.fi;
		for (int l = 0; l < k; ++l) x += q[l]-30;
		mins(ans,Q(x,P(j,k)));
	}
	drep(i,n) {
		R now = dp[i+1][ans.se.fi][ans.se.se];
		y[i] = now.fi.se;
		ans.se = now.se;
	}

	rep(i,n) printf("%d%c",y[i],i==n-1?'\n':' ');
	
	return 0;
}