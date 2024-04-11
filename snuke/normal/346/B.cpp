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
#define pb push_back
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<P,P> Q;
typedef vector<int> vi;

const int MX = 105, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int n, m, r;
string s, t, u;

int l[MX][26];
Q dp[MX][MX][MX];

int main(){
	cin >> s >> t >> u;
	n = s.size();
	m = t.size();
	r = u.size();
	
	string a = "", b, c, d;
	rep(i,r){
		rep(k,26){
			b = a;
			b += 'A'+k;
			c = d = "";
			int x = 0;
			rep(j,i+1){
				c = b[i-j]+c;
				d = d+u[j];
				if(c == d) x = j+1;
			}
			l[i][k] = x;
		}
		a += u[i];
	}
	
	//rep(i,r)rep(j,26) if(l[i][j]) printf("%d %c : %d\n",i,'A'+j,l[i][j]);
	
	rep(i,n+1)rep(j,m+1)rep(k,r) dp[i][j][k] = Q(P(0,-1),P(-1,-1));
	
	rep(i,n)rep(j,m)rep(k,r){
		//printf("%d %d %d %d\n",i,j,k,dp[i][j][k]);
		Q g = Q(P(dp[i][j][k].fi.fi+1,k),P(i,j));
		if(s[i] == t[j]){
			maxs(dp[i+1][j+1][l[k][s[i]-'A']],g);
		}
		maxs(dp[i+1][j][k],dp[i][j][k]);
		maxs(dp[i][j+1][k],dp[i][j][k]);
	}
	rep(i,n)rep(k,r) maxs(dp[i+1][m][k],dp[i][m][k]);
	rep(i,m)rep(k,r) maxs(dp[n][i+1][k],dp[n][i][k]);
	
	Q ans = Q(P(0,-1),P(-1,-1));
	rep(i,r) maxs(ans,dp[n][m][i]);
	
	if(ans.fi.fi == 0) cout << 0 << endl; else {
		string o = "";
		while(ans.fi.fi > 0){
			int ni = ans.se.fi, nj = ans.se.se, nk = ans.fi.se;
			//printf("%d %d %d %d\n",ni,nj,nk, ans.fi.fi);
			o = s[ans.se.fi]+o;
			ans = dp[ni][nj][nk];
		}
		cout << o << endl;
	}
	
	return 0;
}