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
#include <cassert>
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

int n;
int a[200010];

vector<pair<int, ll> > g[200010];

ll val[200010];
int st[200010];

void dfs(int v, ll x){
    val[v] = x;
    st[v] = 1;

    rep(i, g[v].size()){
	if(st[g[v][i].fi] == -1) dfs(g[v][i].fi, x + g[v][i].se);
    }
}

int main(){
    scanf("%d", &n);
    rep(i, n - 1) scanf("%d", &a[i+2]);
    memset(val, -1, sizeof(val));
    memset(st, -1, sizeof(st));

    for(int i = 2; i <= n; ++i){
	ll c;

	int v = i;
	c = a[v];

	v = v + a[v];
	if(v <= 0 || v > n){
	    val[i] = c;
	    st[i] = 1;
	    continue;
	}
	

	c += a[v];
	v = v - a[v];

	if(v <= 0 || v > n){
	    val[i] = c;
	    st[i] = 1;
	    continue;
	}

	if(v == 1){
	    st[i] = 0;
	}

	g[v].pb(mp(i, c));
    }

    for(int i = 2; i <= n; ++i){
	if(st[i] == 1) dfs(i, val[i]);
    }

    for(int i = 1; i < n; ++i){
	ll c = i + a[i+1];

	int v = i + 1;
	v = v - a[v];

	if(v <= 0 || v > n){
	    printf("%I64d\n", c);
	    continue;
	}

	if(v == 1 || val[v] == -1){
	    puts("-1");
	    continue;
	}

	printf("%I64d\n", c + val[v]);
    }

    return 0;
}