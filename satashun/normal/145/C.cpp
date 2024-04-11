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

const ll MOD = 1000000007LL;
int n, k;
ll ret;
int a[100010];
ll dp[1024][1024];
vector<int> vec[10];
vector<int> lu;
int zan;
ll comb[100010];

ll mod_pow(ll x, ll k){
    ll t = 1;
    while(k){
	if(k & 1) t = t * x % MOD;
	x = x * x % MOD;
	k /= 2LL;
    }
    return t;
}

ll inv(ll x){ return mod_pow(x, MOD - 2LL); }

int main(){
    vec[0].pb(0);
    for(int i = 1; i <= 9; ++i){
	for(int x : vec[i-1]){
	    vec[i].pb(x * 10 + 4);
	    vec[i].pb(x * 10 + 7);
	}
    }
    for(int i = 1; i <= 9; ++i){
	for(int x : vec[i]) lu.pb(x);
    }

    scanf("%d %d", &n, &k);
    rep(i, n) scanf("%d", &a[i]);
    sort(a, a + n);

    dp[0][0] = 1;
    rep(i, 1022){
	int num = upper_bound(a, a + n, lu[i]) - lower_bound(a, a + n, lu[i]);	
	for(int j = 0; j <= i; ++j){
	    dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
	    dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j] * (ll)num) % MOD;
	}
    }

    zan = n;
    rep(i, 1022) zan -= (upper_bound(a, a + n, lu[i]) - lower_bound(a, a + n, lu[i]));
    
    comb[0] = 1;
    for(int i = 1; i <= zan; ++i){
	comb[i] = comb[i-1] * (ll)(zan + 1 - i) % MOD * inv((ll)i) % MOD; 
    }

    for(int i = 0; i <= k; ++i){
	if(i <= 1022 && k - i <= zan){
	    ret = (ret + comb[k - i] * dp[1022][i]) % MOD;
	}
    }
    printf("%I64d\n", ret);
    return 0;
}