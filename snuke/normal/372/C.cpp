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
#include<complex>
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
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define adds(x,y) x = (x+(y))%mod;
#define dels(x,y) x = (x-(y)+mod)%mod;
#define muls(x,y) x = ((ll)x*(y))%mod;
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 150005, MY = 305, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int dp[MY][MX];

int a[MY], b[MY], t[MY];
int q[MX], qs, qt;

int main(){
	int n, m, d;
	ll sum = 0;
	
	scanf("%d%d%d",&n,&m,&d);
	rep(i,m){
		scanf("%d%d%d",&a[i],&b[i],&t[i]);
		t[i]--; a[i]--;
		sum += b[i];
	}
	
	int i = 0, si, nt, dt = 0, co, di = 0; ll cd;
	while(i < m){
		nt = t[i];
		si = i;
		while(i < m && t[i] == nt) i++;
		cd = min((ll)n,(ll)(nt-dt)*d);
		//printf("%d %d %d %d\n",i,nt,si,di);
		qs = qt = 0;
		rep(j,n*2+5){
			if(j<n){ while(qs<qt&&dp[di][j]<=dp[di][q[qt-1]]) qt--;}
			while(qs<qt&&q[qs]<j-cd*2) qs++;
			if(j<n) q[qt++] = j;
			if(j-cd >= 0 && j-cd < n) dp[di+1][j-cd] = dp[di][q[qs]];
		}
		
		rep(j,n){
			co = 0;
			for(int k = si; k < i; k++) co += abs(j-a[k]);
			dp[di+1][j] += co;
		}
		dt = nt; di++;
	}
	
	int ans = INF;
	rep(i,n) mins(ans,dp[di][i]);
	
	cout << sum-ans << endl;
	
	return 0;
}