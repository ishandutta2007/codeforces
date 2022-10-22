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

ll MOD = 1000000007;

string a, s;
int k, l;
ll mu[100010];
ll ret;

ll mod_pow(ll x, ll ke, ll mod) {
    ll ret = 1;
    while (ke) {
	if (ke & 1) ret = ret * x % mod;
	x = x * x % mod;
	ke >>= 1;
    }
    return ret;
}

ll fermat_inv_mod(ll num, ll p) {
    return mod_pow(num, p - 2, p);
}

int main(){
    cin >> a >> k;
    l = (int)a.size();

    mu[0] = 1LL;
    for(int i = 1; i <= 100000; ++i) mu[i] = mu[i - 1] * 2LL % MOD;

    rep(i, a.size()){
	if(a[i] == '0' || a[i] == '5'){
	    ret += mu[i];
	    ret %= MOD;
	}
    }

    ll mul = (mod_pow(mu[l], k, MOD) - 1);
    if(mul < 0) mul += MOD;
    ret = ret * mul % MOD;

    ll wa = mu[l] - 1;
    ll inv = fermat_inv_mod(wa, MOD);
    ret = ret * inv % MOD;
    cout << ret << endl;
    return 0;
}