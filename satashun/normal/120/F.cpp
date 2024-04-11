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
const double EPS = 1e-6;
const double PI  = acos(-1.0);
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int n, m;
int ret;
vector<int> g[110];
int d[110];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    while(n--){
	cin >> m;

	rep(i, m){
	    g[i].clear();
	    d[i] = -1;
	}

	rep(i, m - 1){
	    int a, b;
	    cin >> a >> b;
	    --a; --b;
	    g[a].pb(b);
	    g[b].pb(a);
	}

	queue<int> que;
	que.push(0);
	d[0] = 0;

	while(!que.empty()){
	    int t = que.front(); que.pop();
	    rep(i, g[t].size()){
		if(d[g[t][i]] == -1){
		    d[g[t][i]] = d[t] + 1;
		    que.push(g[t][i]);
		}
	    }
	}

	int piv = -1, ma = -1;
	rep(i, m){
	    if(d[i] > ma){
		ma = d[i];
		piv = i;
	    }
	    d[i] = -1;
	}

	que.push(piv);
	d[piv] = 0;

	while(!que.empty()){
	    int t = que.front(); que.pop();
	    rep(i, g[t].size()){
		if(d[g[t][i]] == -1){
		    d[g[t][i]] = d[t] + 1;
		    que.push(g[t][i]);
		}
	    }
	}

	ma = -1;
	rep(i, m) if(d[i] > ma) ma = d[i];
	ret += ma;
    }
    cout << ret << endl;
}