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

#define SZ (1 << 20)

int n, m;
int a[100010];

struct segtree{
    bool dat[SZ * 2];

    void init(){
	memset(dat, false, sizeof(dat));
    }

    inline void update(int k, bool fl){
	k += SZ - 1;
	dat[k] = fl;
	while(k > 0){
	    k = (k - 1) / 2;
	    dat[k] = dat[k * 2 + 1] && dat[k * 2 + 2];
	}
    }

    bool query(int a, int b, int k = 0, int l = 0, int r = SZ){
	if(r <= a || b <= l) return true;
	if(a <= l && r <= b) return dat[k];
	bool lc = query(a, b, k * 2 + 1, l, (l + r) / 2);
	bool rc = query(a, b, k * 2 + 2, (l + r) / 2, r);
	return lc && rc;
    }

};

segtree inc, de;

int main(){
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    inc.init(); de.init();
    rep(i, n - 1){
	if(a[i] <= a[i + 1]) inc.update(i, true);
	if(a[i] >= a[i + 1]) de.update(i, true);
    }
    rep(i, m){
	int p, q;
	cin >> p >> q;
	--p; --q;
	int lb = p - 1, ub = q + 1;
	while(ub - lb > 1){
	    int mid = (ub + lb) / 2;
	    if(inc.query(p, mid)) lb = mid;
	    else ub = mid;
	}
	if(de.query(lb, q)) cout << "Yes" << endl;
	else cout << "No" << endl;
    }
    /*
    rep(i, n){
	for(int j = i; j < n; ++j){
	    int p = i;
	    int q = j;
	    cout << i  + 1 << " " << j + 1 << " ";
	    int lb = p - 1, ub = q + 1;
	    while(ub - lb > 1){
		int mid = (ub + lb) / 2;
		if(inc.query(p, mid)) lb = mid;
		else ub = mid;
	    }
	    cout << lb << " ";
	    if(de.query(lb, q)) cout << "Yes" << endl;
	    else cout << "No" << endl;
	}
    }
    */
    return 0;
}