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
typedef pair<int, int> pii;
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
vector<pii> g[100010];
int sz[100010];
int ok[100010];
int ot[100010];
bool vis[100010];
ll ret;

void dfs1(int v, int p){
    sz[v] = 1;

    for(pii e : g[v]) if(e.fi != p){
	dfs1(e.fi, v);
	if(e.se) ok[v] += sz[e.fi];
	else ok[v] += ok[e.fi];
	sz[v] += sz[e.fi];
    }
}

int main(){
    scanf("%d", &n);
    rep(i, n - 1){
	int a, b; char c[20];
	scanf("%d %d %s", &a, &b, c);
	--a; --b;

	int len = strlen(c);
	bool f = true;
	rep(j, len) if(c[j] != '4' && c[j] != '7') f = false;
	g[a].pb(mp(b, f));
	g[b].pb(mp(a, f));
    }
    dfs1(0, -1);

    queue<int> que;
    que.push(0);

    while(!que.empty()){
	int v = que.front(); que.pop();
	vis[v] = true;

	for(pii e : g[v]){
	    if(vis[e.fi]) continue;
	    if(e.se) ot[e.fi] = n - sz[e.fi];
	    else ot[e.fi] = ot[v] + ok[v] - ok[e.fi];
	    que.push(e.fi);
	}
    }

    rep(i, n){
	ret += (ll)ok[i] * (ok[i] - 1);
	ret += (ll)ot[i] * (ot[i] - 1);
	ret += (ll)ok[i] * ot[i] * 2;
    }
    printf("%I64d\n", ret);
    return 0;
}