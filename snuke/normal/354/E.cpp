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
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define adds(x,y) x = (x+(y))%mod;
#define muls(x,y) x = (x*(y))%mod;
#define pb push_back
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 25, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v
const int lu[3] = {0,4,7};

int now[6];
int luc[50][6];
int l[50], ls;
int t[MX];
vector<int> dp[MX][11];

void dfs(int dep, int sum){
	if(dep == 0){
		if(luc[sum][0] != -1) return;
		rep(i,6) luc[sum][i] = now[i];
		return;
	}
	rep(i,3){
		now[dep-1] = lu[i];
		dfs(dep-1,sum+lu[i]);
	}
}

int main(){
	rep(i,50) luc[i][0] = -1;
	dfs(6,0);
	
	rep(i,50) if(luc[i][0] != -1) l[ls++] = i;
	
	int n, d;
	ll x;
	cin >> n;
	rep(ti,n){
		cin >> x;
		ll a = 1000000000000000000;
		rep(i,19){
			t[i] = x/a%10;
			a /= 10;
		}
		
		rep(i,20)rep(j,10) dp[i][j].clear();
		dp[0][0].pb(-1);
		rep(i,19)rep(j,10)rep(k,ls){
			if(dp[i][j].size() == 0) continue;
			d = j*10+t[i]-l[k];
			if(d >= 0 && d < 10 && dp[i+1][d].size() == 0){
				dp[i+1][d] = dp[i][j];
				dp[i+1][d].pb(l[k]);
			}
		}
		
		if(dp[19][0].size()){
			rep(i,6){
				a = 0;
				rrep(j,19) a = a*10+luc[dp[19][0][j]][i];
				cout << a << (i == 5 ? '\n' : ' ');
			}
		} else puts("-1");
	}
	
	return 0;
}