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

int n, m, r;
int a[3010];
vector<pii> ans;

struct unionfind{
    int par[3010], rank[3010];

    void init(){
	rep(i, 3010){
	    par[i] = i;
	    rank[i] = 0;
	}
    }

    inline int find(int x){
	if(par[x] == x) return x;
	else return par[x] = find(par[x]);
    }

    inline void unite(int x, int y){
	x = find(x); y = find(y);
	if(x == y) return ;
	if(rank[x] < rank[y]) par[x] = y;
	else{
	    par[y] = x;
	    rank[x] += rank[x] == rank[y];
	}
    }

    bool same(int x, int y){
	return find(x) == find(y);
    }

}uf;

vector<int> c[3010];

int main(){
    cin >> n;
    rep(i, n){
	cin >> a[i];
	--a[i];
    }
    cin >> m;
    r = n - m;

    int cur;

    while(true){
	uf.init();
	cur = n;

	rep(i, n){
	    c[i].clear();
	    if(i != a[i] && !uf.same(i, a[i])){
		uf.unite(i, a[i]);
		--cur;
	    }
	}

	if(cur == r) break;

	if(cur < r){
	    bool f = false;

	    rep(i, n){
		c[uf.find(i)].pb(i);
	    }
	    
	    rep(i, n){
		int p = uf.find(i);
		if(c[p].size() >= 2){
		    ans.pb(mp(c[p][0] + 1, c[p][1] + 1));
		    swap(a[c[p][0]], a[c[p][1]]);
		    break;
		}
		/*
		for(int j = i + 1; j < n; ++j){
		    if(uf.same(i, j)){
			ans.pb(mp(i + 1, j + 1));
			swap(a[i], a[j]);
			f = true;
			break;
		    }
		}
		if(f) break;
		*/
	    }
	}else{
	    bool f = false;
	    rep(i, n){
		for(int j = i + 1; j < n; ++j){
		    if(!uf.same(i, j)){
			ans.pb(mp(i + 1, j + 1));
			swap(a[i], a[j]);
			f = true;
			break;
		    }
		}
		if(f) break;
	    }
	}
    }

    cout << ans.size() << "\n";
    rep(i, ans.size()) cout << ans[i].fi << " " << ans[i].se << (i == (int)ans.size() - 1 ? '\n' : ' ');
    return 0;
}