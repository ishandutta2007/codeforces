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

typedef pair<P, int> PT;

int n, m;
ll ad[5010];
vector<PT> vm, vad;
vector<int> op;
ll mk[5010];
ll ans[5010];

/*
ll abs(ll x){
    if(x >= 0) return x;
    else return -x;
}
*/

int main(){
    cin >> n >> m;
    fill(mk, mk + 5005, LLONG_MAX / 2LL);
    rep(i, m){
	int t;
	cin >> t;
	op.pb(t);
	if(t == 1){
	    int l, r; ll d;
	    cin >> l >> r >> d;
	    --l; --r;
	    for(int j = l; j <= r; ++j) ad[j] += d;
	    vad.pb(mp(mp(l, r), d));
	}else{
	    int l, r; ll mi;
	    cin >> l >> r >> mi;
	    --l; --r;
	    for(int j = l; j <= r; ++j) mk[j] = min(mk[j], mi - ad[j]);
	    vm.pb(mp(mp(l, r), mi));
	}
    }
    
    rep(i, n) ans[i] = mk[i]; 
    int a = 0, b = 0;
    rep(i, m){
	if(op[i] == 1){
	    int l, r; ll d;
	    l = vad[a].fi.fi;
	    r = vad[a].fi.se;
	    d = vad[a].se;
	    for(int j = l; j <= r; ++j) mk[j] += d;
	    ++a;
	}else{
	    int l, r; ll mi;
	    l = vm[b].fi.fi;
	    r = vm[b].fi.se;
	    mi = vm[b].se;
	    ll ma = LLONG_MIN;
	    for(int j = l; j <= r; ++j) ma = max(ma, mk[j]);
	    if(ma != mi){
		cout << "NO" << endl;
		return 0;
	    }
	    ++b;
	}
    }
    cout << "YES" << endl;
    rep(i, n){
	if(abs(ans[i]) > 1000000000) ans[i] = 0;
	cout << ans[i];
	if(i == n - 1) cout << endl;
	else cout << " ";
    }
    return 0;
}