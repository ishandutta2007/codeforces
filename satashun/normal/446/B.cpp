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

int n, m, k, p;
ll ret;
ll a[1010][1010];
ll rs[1010], cs[1010];
int sz;
ll sr, ss;
ll dp1[1000010], dp2[1000010];

struct segtree_max{
    vector<pair<ll, int> > dat;

    void init(int n_){
	sz = 1;
	while(sz < n_) sz *= 2;
	dat.resize(sz * 2);
	for(int i = sz - 1; i < sz * 2 - 1; ++i) dat[i] = mp(LLONG_MIN, i - sz + 1);
	for(int i = sz - 2; i >= 0; --i) dat[i] = max(dat[i * 2 + 1], dat[i * 2 + 2]);
    }

    void update(int pos, ll x){
	pos += sz - 1;
	dat[pos].fi = x;

	while(pos > 0){
	    pos = (pos - 1) / 2;
	    dat[pos] = max(dat[pos * 2 + 1], dat[pos * 2 + 2]);
	}
    }

    pair<ll, int> get(int a, int b, int k = 0, int l = 0, int r = sz){
	if(b <= l || r <= a) return mp(LLONG_MIN, -1);
	if(a <= l && r <= b) return dat[k];
	return max(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
    }
}r, c;

int main(){
    scanf("%d %d %d %d", &n, &m, &k, &p);
    rep(i, n) rep(j, m) scanf("%I64d", &a[i][j]);

    rep(i, n){
	rep(j, m){
	    rs[i] += a[i][j];
	    cs[j] += a[i][j];
	}
    }

    r.init(max(n, m));
    c.init(max(n, m));

    rep(i, n) r.update(i, rs[i]);
    rep(i, m) c.update(i, cs[i]);

    rep(i, k){
	pair<ll, int> mr = r.get(0, n);
	dp1[i + 1] = dp1[i];
	dp1[i + 1] += mr.fi;
	r.update(mr.se, mr.fi - (ll)p * m);
    }

    rep(i, k){
	pair<ll, int> ms = c.get(0, m);
	dp2[i + 1] = dp2[i];
	dp2[i + 1] += ms.fi;
	c.update(ms.se, ms.fi - (ll)p * n);
    }

    ret = LLONG_MIN;
    for(int i = 0; i <= k; ++i){
	ll x = dp1[i] + dp2[k-i] - (ll)p * i * (k - i);
	ret = max(ret, x);
    }


    /*
    rep(i, k){
	pair<ll, int> mr = r.get(0, n), ms = c.get(0, m);
	if(mr.fi - ss >= ms.fi - sr){
	    ret += mr.fi - ss;
	    sr += p;
	    r.update(mr.se, mr.fi - (ll)p * m);
	}else{
	    ret += ms.fi - sr;
	    ss += p;
	    c.update(ms.se, ms.fi - (ll)p * n);
	}
    }
    */

    printf("%I64d\n", ret);
    return 0;
}