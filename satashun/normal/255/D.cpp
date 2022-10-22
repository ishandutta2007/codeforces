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

//
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int n, x, y, c;

inline ll san(ll k){
    return k * (k + 1) / 2;
}

inline ll sqr(ll k){
    return k * k;
}

bool C(ll k){
    ll sz;
    sz = 2LL * (ll)(k) * (ll)(k + 1) + 1;
    ll lh = max(0LL, k - (x - 1));
    ll rh = max(0LL, k - (n - x));
    ll uh = max(0LL, k - (y - 1));
    ll dh = max(0LL, k - (n - y));
    ll a = max(0LL, k - (x + y - 1));
    ll b = max(0LL, k - (x + n - y));
    ll d = max(0LL, k - (n - x + y));
    ll e = max(0LL, k - (n - x + n - y + 1));
    sz -= sqr(lh) + sqr(rh) + sqr(uh) + sqr(dh);
    sz += san(a) + san(b) + san(d) + san(e);
    if(sz >= c) return true;
    else return false;
}

int main(){
    cin >> n >> x >> y >> c;
    ll lb = 0, ub = (ll)n * 3LL;
    if(C(0)){
	printf("0\n");
	return 0;
    }
    while(ub - lb > 1){
	ll mid = (ub + lb) / 2;
	if(C(mid)) ub = mid;
	else lb = mid;
    }
    cout << ub << endl;
    return 0;
}