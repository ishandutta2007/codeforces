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

class unionfind {   
    public:
    vector<int> par, rank; 
    void init(int n) {
	par.resize(n);
	rank.resize(n);

	for(int i = 0; i < n; i++) {
	    par[i] = i;
	    rank[i] = 0;
	}
    }

    int find(int x) {
	if(par[x] == x) return x;
	else return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return ;

	if(rank[x] < rank[y]) par[x] = y;
	else{
	    par[y] = x;
	    if(rank[x] == rank[y]) ++rank[x];
	}
    }

};

unionfind uf[2][10010];
int n, m, q;
pii e[10010];
bool f[510];

int main(){
    scanf("%d %d", &n, &m);
    rep(i, m){
	scanf("%d %d", &e[i].fi, &e[i].se);
	--e[i].fi; --e[i].se;
    }

    rep(i, m + 1) rep(j, 2) uf[j][i].init(n);
    rep(i, m){
	uf[0][i+1] = uf[0][i];
	uf[0][i+1].unite(e[i].fi, e[i].se);
    }

    for(int i = m - 1; i >= 0; --i){
	uf[1][i] = uf[1][i+1];
	uf[1][i].unite(e[i].fi, e[i].se);
    }

    scanf("%d", &q);
    while(q--){
	CLR(f);
	int l, r;
	scanf("%d %d", &l, &r);
	unionfind T = uf[0][l-1];

	vector<int> vec[510];
	rep(i, n) vec[uf[1][r].find(i)].pb(i);

	rep(i, n)
	    rep(j, (int)vec[i].size() - 1)
		T.unite(vec[i][j], vec[i][j+1]);
	
	rep(i, n) f[T.find(i)] = true;
	int t = 0;
	rep(i, n) t += f[i];
	printf("%d\n", t);
    }

    return 0;
}