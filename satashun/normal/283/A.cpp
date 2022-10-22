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

#define sz (1 << 20)

int n;
int si;

struct NODE{
    ll lazy, sum;
    NODE(){ lazy = sum = 0LL; }
};

struct segtree{
    NODE dat[sz * 2];

    inline void lazy_eval(int k, int a, int b){
	dat[k].sum += dat[k].lazy * (ll)(b - a);
	if(k < sz - 1){
	    dat[k * 2 + 1].lazy += dat[k].lazy;
	    dat[k * 2 + 2].lazy += dat[k].lazy;
	}
	dat[k].lazy = 0LL;
    }

    inline void update_node(int k){ dat[k].sum = dat[k * 2 + 1].sum + dat[k * 2 + 2].sum; }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = sz){
	lazy_eval(k, l, r);
	if(r <= a || b <= l) return ;
	if(a <= l && r <= b){
	    dat[k].lazy += x;
	    lazy_eval(k, l, r);
	    return ;
	}
	add(a, b, x, k * 2 + 1, l, (l + r) / 2);
	add(a, b, x, k * 2 + 2, (l + r) / 2, r);
	update_node(k);
    }

    ll sum(int a, int b, int k = 0, int l = 0, int r = sz){
	lazy_eval(k, l, r);
	if(r <= a || b <= l) return 0LL;
	if(a <= l && r <= b) return dat[k].sum;
	ll ret = sum(a, b, k * 2 + 1, l, (l + r) / 2) + sum(a, b, k * 2 + 2, (l + r) / 2, r);
	update_node(k);
	return ret;
    }
}seg;

int main(){
    scanf("%d", &n);
    si = 1;
    rep(i, n){
	int t;
	scanf("%d", &t);
	if(t == 1){
	    int a, x;
	    scanf("%d %d", &a, &x);
	    seg.add(0, a, (ll)x);
	}else if(t == 2){
	    int k;
	    scanf("%d", &k);
	    ++si;
	    seg.add(si - 1, si, (ll)k);
	}else{
	    --si;
	    ll dec = seg.sum(si, si + 1);
	    seg.add(si, si + 1, (-1LL) * dec);
	}
	printf("%.8lf\n", (double)seg.sum(0, si) / (double)si);
    }
    return 0;
}