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

struct edge{
    int to, dir;
    edge(int to, int dir) : to(to), dir(dir){}
    edge(){}
};

int n, ret = 300000;
vector<int> ans;
vector<edge> g[200010];
int dp[200010];
int up[200010];
int dep[200010];

void dfs(int v, int p, int d, int k){
    dep[v] = d;
    up[v] = k;
    rep(i, g[v].size()) if(g[v][i].to != p){
	dfs(g[v][i].to, v, d + 1, k + g[v][i].dir);
	dp[v] += dp[g[v][i].to] + g[v][i].dir;
    }
}

int main(){
    scanf("%d", &n);
    rep(i, n - 1){
	int s, t;
	scanf("%d %d", &s, &t);
	--s; --t;
	g[s].pb(edge(t, 0));
	g[t].pb(edge(s, 1));
    }
    dfs(0, -1, 0, 0);

    rep(i, n){
	int x = dp[0] + dep[i] - up[i] * 2;
	if(x == ret) ans.pb(i + 1);
	else if(x < ret){
	    ret = x;
	    ans.clear();
	    ans.pb(i + 1);
	}
    }
    printf("%d\n", ret);
    rep(i, ans.size()){
	printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}