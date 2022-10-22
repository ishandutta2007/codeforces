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
int ret;
int dia[210];
vector<int> g[210];
int ch[210];
int dep[210];
int pa[210];

void dfs(int v, int p){
    ch[v] = 0;
    pa[v] = p;
    
    vector<int> vec;
    for(int to : g[v]) if(to != p){
	dfs(to, v);
	vec.pb(ch[to] + 1);
	ch[v] = max(ch[v], ch[to] + 1);
	dia[v] = max(dia[v], dia[to]);	
    }
    vec.pb(0); vec.pb(0);
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    dia[v] = max(dia[v], vec[0] + vec[1]);
}


int main(){
    scanf("%d", &n);
    rep(i, n - 1){
	int a, b;
	scanf("%d %d", &a, &b);
	--a; --b;
	g[a].pb(b);
	g[b].pb(a);
    }

    rep(r, n){ //root
	memset(dia, -1, sizeof(dia));
	memset(dep, -1, sizeof(dep));	
	dfs(r, -1);
	queue<int> q;
	q.push(r);

	dep[r] = 0;
	while(!q.empty()){
	    int v = q.front(); q.pop();
	    for(int to : g[v]){
		if(dep[to] == -1){
		    dep[to] = dep[v] + 1;
		    q.push(to);
		}
	    }
	}

	//rep(i, n) cout << dia[i] << " ";
	//cout << endl;

	rep(v, n){
	    for(auto to : g[v]){
		if(to == pa[v]) continue;
		for(auto to2 : g[v]) if(to2 != to && to2 != pa[v]){
		    ret = max(ret, (dep[to] + ch[to]) * dia[to2]);
		}
	    }
	}	
    }

    printf("%d\n", ret);
    return 0;
}