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

//
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int n, m, k;
vector<int> g[100010];
bool vis[100010];
vector<int> ans;
set<int> nei;

void dfs(int vert){
    ans.pb(vert);
    vis[vert] = true;
    bool f = false;
    rep(i, g[vert].size()){
	if(!vis[g[vert][i]]){
	    dfs(g[vert][i]);
	    f = true;
	    break;
	}
    }
    if(!f) return;
    vis[vert] = false;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    rep(i, m){
	int a, b;
	scanf("%d %d", &a, &b);
	a--; b--;
	g[a].pb(b);
	g[b].pb(a);
    }
    dfs(0);
    int sz = ans.size();
    int v = ans[sz - 1];
    rep(i, g[v].size()) nei.insert(g[v][i]);
    int crt = 0;
    while(nei.find(ans[crt]) == nei.end()) crt++;
    printf("%d\n", (int)ans.size() - crt);
    for(int i = crt; i < ans.size(); i++) printf("%d%c", ans[i] + 1, i == ans.size() - 1 ? '\n' : ' ');
    return 0;
}