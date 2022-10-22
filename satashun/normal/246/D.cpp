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
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int n, m;
int c[100010];
set<int> col;
vector<int> g[100010], v[100010];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
	scanf("%d", &c[i]);
	col.insert(c[i]);
	v[c[i]].pb(i);
    }
    for(int i = 0; i < m; i++){
	int a, b;
	scanf("%d %d", &a, &b);
	a--; b--;
	g[a].pb(b); g[b].pb(a);
    }
    int ans = -1;
    int ma = -1;
    for(set<int>::iterator it = col.begin(); it != col.end(); it++){
	int crt = *it;
	set<int> tmp;
	for(int i = 0; i < v[crt].size(); i++){
	    int pos = v[crt][i];
	    for(int j = 0; j < g[pos].size(); j++){
		if(c[g[pos][j]] != crt) tmp.insert(c[g[pos][j]]);
	    }
	}
	int sz = tmp.size();
	if(sz > ma){
	    ma = sz;
	    ans = crt;
	}
    }
    printf("%d\n", ans);
    return 0;
}