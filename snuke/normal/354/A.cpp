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

const int MX = 100005, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int x[MX], y[MX];

int main(){
	int n, l, r, l2, r2;
	scanf("%d%d%d%d%d",&n,&l,&r,&l2,&r2);
	
	rep(i,n){
		scanf("%d",&x[i]);
		y[i] = x[i];
	}
	
	rep(i,n) x[i+1] += x[i];
	drep(i,n) y[i] += y[i+1];
	
	ll ans = LINF;
	
	ll pre = 0;
	rep(i,n+1){
		int lc = 0, rc = 0, rs = n-i;
		if(i > rs) lc = l2*(i-rs-1);
		if(i < rs) rc = r2*(rs-i-1);
		mins(ans,pre*l+y[i]*r+lc+rc);
		pre = x[i];
	}
	
	cout << ans << endl;
	
	return 0;
}