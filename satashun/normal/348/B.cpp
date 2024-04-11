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

int n;
ll ret;
ll a[100010];
vector<int> g[100010];

ll lcm(ll p, ll q){
    return p / (ll)__gcd(p, q) * q;
};

pair<ll, ll> dfs(int v, int p){
    if(g[v].size() == 1 && g[v][0] == p) return mp(a[v], 1LL);

    ll s = 0LL;
    ll ha = 0LL;
    ll mi = LLONG_MAX;
    ll now = 0LL;
    vector<pair<ll, ll> > vec;

    ll ch = 1LL;
    bool f = false;
    rep(i, g[v].size()) if(g[v][i] != p){
	vec.pb(dfs(g[v][i], v));
	mi = min(mi, vec[(int)now].fi);
	if(ch < LLONG_MAX) ch = lcm(ch, vec[(int)now].se);
	if(ch > vec[(int)now].fi) f = true;
	ha += vec[(int)now].se;
	now++;
    }

    ll gen = LLONG_MAX;
    if(f) ch = LLONG_MAX;
    gen = mi / ch * ch;
    //cout << mi << endl;
    /*
    rep(i, now){
	gen = min(gen, mi / vec[i].se * vec[i].se);
    }
    */

    rep(i, now){
	ret += vec[i].fi - gen;
    }
    //cout << v << " " << gen << " " << ha << endl << gen * now << endl;
    ll ze;
    if(ch == LLONG_MAX) ze = ch;
    else ze = ch * now;
    return mp(gen * now, ze);
}

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n - 1){
	int b, c;
	cin >> b >> c;
	--b; --c;
	g[b].pb(c);
	g[c].pb(b);
    }
    dfs(0, -1);
    cout << ret << endl;
    return 0;
}

/*
10
0 100000000 100000000 100000000 100000000 100000000 100000000 100000000 100000000 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10

6
0 0 10 9 6 7
1 2
1 3
1 4
2 5
2 6
*/