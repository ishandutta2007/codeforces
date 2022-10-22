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

int n, q;
int a[1 << 18];
vector<int> vec[100010];
vector<int> xs;

int sz;

struct segtree_gcd{
    vector<int> dat;

    void init(int n_){
	sz = 1;
	while(sz < n_) sz *= 2;
	for(int i = n_; i < sz; ++i) a[i] = 1;
	dat.resize(sz * 2);

	for(int i = sz - 1; i <= sz * 2 - 2; ++i) dat[i] = a[i + 1 - sz];
	for(int i = sz - 2; i >= 0; --i) dat[i] = __gcd(dat[i*2+1], dat[i*2+2]);
    }

    int get(int a, int b, int k = 0, int l = 0, int r = sz){
	if(b <= l || r <= a) return INT_MAX;
	if(a <= l && r <= b) return dat[k];
	int lch = get(a, b, k * 2 + 1, l, (l + r) / 2);
	int rch = get(a, b, k * 2 + 2, (l + r) / 2, r);
	if(lch == INT_MAX) return rch;
	else if(rch == INT_MAX) return lch;
	else return __gcd(lch, rch);
    }
}segg;

struct segtree_max{
    vector<int> dat;

    void init(){
	dat.resize(sz * 2);
	rep(i, sz * 2) dat[i] = INT_MAX;
    }

    void update(int pos, int x){
	pos += sz - 1;
	dat[pos] = x;

	while(pos > 0){
	    pos = (pos - 1) / 2;
	    dat[pos] = min(dat[pos * 2 + 1], dat[pos * 2 + 2]);
	}
    }

    int get(int a, int b, int k = 0, int l = 0, int r = sz){
	if(b <= l || r <= a) return INT_MAX;
	if(a <= l && r <= b) return dat[k];
	return min(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
    }
}segm;

int main(){
    scanf("%d", &n);
    xs.pb(1);

    rep(i, n){
	scanf("%d", &a[i]);
	xs.pb(a[i]);
    }

    segg.init(n);
    segm.init();

    rep(i, n) segm.update(i, a[i]);

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    rep(i, n) vec[lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin()].pb(i);

    scanf("%d", &q);
    while(q--){
	int l, r;
	scanf("%d %d", &l, &r);
	--l;
	int m = segm.get(l, r);
	int zan = r - l;
	if(segg.get(l, r) % m == 0){
	    int p = lower_bound(xs.begin(), xs.end(), m) - xs.begin();
	    int d = lower_bound(vec[p].begin(), vec[p].end(), r) - lower_bound(vec[p].begin(), vec[p].end(), l);
	    zan -= d;
	}
	printf("%d\n", zan);
    }
    return 0;
}