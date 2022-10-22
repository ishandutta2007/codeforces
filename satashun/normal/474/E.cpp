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
typedef pair<ll, int> pli;

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
ll d; 
int sz; 
vector<ll> xs;
ll a[100010];
int p[100010];
int pre[100010];
map<int, int> m;

struct segtree_max{
    vector<pli> dat;

    void init(int n_){
	sz = 1;
	while(sz < n_) sz *= 2;
	dat.resize(sz * 2);
	for(int i = sz - 1; i <= sz * 2 - 2; ++i) dat[i] = mp(LLONG_MIN, i + 1 - sz);
	for(int i = sz - 2; i >= 0; --i) dat[i] = max(dat[i*2+1], dat[i*2+2]);
    }

    void update(int pos, ll x){
	pos += sz - 1;
	dat[pos].fi = x;

	while(pos > 0){
	    pos = (pos - 1) / 2;
	    dat[pos] = max(dat[pos * 2 + 1], dat[pos * 2 + 2]);
	}
    }

    pli get(int a, int b, int k = 0, int l = 0, int r = sz){
	if(b <= l || r <= a) return mp(LLONG_MIN, -1);
	if(a <= l && r <= b) return dat[k];
	return max(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
    }
}seg;

int main(){
    scanf("%d %I64d", &n, &d);
    xs.resize(n * 3);
    rep(i, n){
	scanf("%I64d", &a[i]);
	xs[i*3] = a[i];
	xs[i*3+1] = a[i] - d;
	xs[i*3+2] = a[i] + d;
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    rep(i, n) p[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin();
    seg.init(xs.size());
    seg.update(p[0], 1);
    pre[0] = -1;
    m[p[0]] = 0;

    //cout << endl;
    for(int i = 1; i < n; ++i){
	ll lo = a[i] - d, hi = a[i] + d;
	lo = upper_bound(xs.begin(), xs.end(), lo) - xs.begin();
	hi = lower_bound(xs.begin(), xs.end(), hi) - xs.begin();

	//cout << i << " " << lo << " " << hi << endl;

	pli s = mp(LLONG_MIN, -1), t = mp(LLONG_MIN, -1);
	s = seg.get(0, lo);
	t = seg.get(hi, xs.size());

	//cout << i << " " << s.fi << " " << s.se << endl;
	//cout << i << " " << t.fi << " " << t.se << endl;		
	s = max(s, t);

	if(s.fi != LLONG_MIN){
	    //cout << i << " " << a[i] << " " << s.fi << " " << xs[p[s.se]] << endl;
	    pre[i] = m[s.se];
	    seg.update(p[i], s.fi + 1);    
	}else{
	    pre[i] = -1;
	    seg.update(p[i], 1);
	}
	m[p[i]] = i;	
	//cout << endl;
    }

    pli s = seg.get(0, xs.size());
    printf("%I64d\n", s.fi);
    int cur = m[s.se];
    vector<int> ans(s.fi);

    rep(i, s.fi){
	ans.pb(cur + 1);
	cur = pre[cur];
    }
    reverse(ans.begin(), ans.end());
    rep(i, s.fi) printf("%d%c", ans[i], i != s.fi - 1 ? ' ' : '\n');
    return 0;
}