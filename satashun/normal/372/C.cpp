//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <climits>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define fi first
#define se second

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int m;
ll n, d;
ll ret = LLONG_MIN;
vector<ll> tx;
vector<pair<int, ll> > ff[310];
int now;
ll la;
ll dp[2][150010];
int deq[150010];

int main(){
    scanf("%I64d %d %I64d", &n, &m, &d);
    rep(i, m){
	int a; ll b, c;
	scanf("%d %I64d %I64d", &a, &b, &c);
	tx.pb(c);
	if(i == 0 || c == la){
	    ff[now].pb(mp(a, b));
	    la = c;
	}else{
	    ++now;
	    ff[now].pb(mp(a, b));
	    la = c;
	}
    }
    tx.erase(unique(tx.begin(), tx.end()), tx.end());
    
    for(int i = 1; i <= n; ++i){
	ll x = 0;
	rep(j, ff[0].size()) x += ff[0][j].se - (ll)abs(ff[0][j].fi - i);
	dp[0][i] = x;
    }

    for(int i = 1; i <= now; ++i){
	int s = 0, t = 0;
	ll w = d * (tx[i] - tx[i-1]);
	int r = min(n, w);

	for(int j = 1; j <= r; ++j) {
	    while(s < t && dp[(i-1)&1][deq[t-1]] <= dp[(i-1)&1][j]) --t;
	    deq[t++] = j;
	}

	for(int j = 1; j <= n; ++j){
	    if(r + 1 <= n){
		++r;
		while(s < t && dp[(i-1)&1][deq[t-1]] <= dp[(i-1)&1][r]) --t;
		deq[t++] = r;
	    }
	    dp[i&1][j] = dp[(i-1)&1][deq[s]];
	    if((ll)deq[s] == (ll)j - w) ++s;
	    
	    ll x = 0;
	    rep(k, ff[i].size()) x += ff[i][k].se - abs(ff[i][k].fi - j);
	    dp[i&1][j] += x;
	    
	}
	
    }
    for(int i = 1; i <= n; ++i) ret = max(ret, dp[now&1][i]);
    printf("%I64d\n", ret);
    return 0;
}