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
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 4000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

struct dat {
	int x, k, m;
	dat(){}
	dat(int x, int k, int m):x(x),k(k),m(m){}
	bool operator<(const dat& a)const{return k<a.k;}
};

ll dp[1<<20];

int main(){
	int n, m, b;
	scanf("%d%d%d",&n,&m,&b);
	ll ans = LINF;
	vector<dat> d;
	rep(i,n) {
		int x, k, ms, msk = 0;
		scanf("%d%d%d",&x,&k,&ms);
		rep(j,ms) {
			int a;
			scanf("%d",&a);
			msk |= 1<<a-1;
		}
		d.pb(dat(x,k,msk));
	}
	int m2 = 1<<m;
	rep(i,m2) dp[i] = LINF;
	dp[0] = 0;
	sort(rng(d));
	rep(i,n) {
		rep(j,m2) {
			mins(dp[j|d[i].m], dp[j]+d[i].x);
		}
		mins(ans, dp[m2-1]+(ll)d[i].k*b);
	}

	if (ans == LINF) ans = -1;
	cout << ans << endl;
	
	return 0;
}