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

const ll MOD = 1000000007LL;

int n, m;
ll acc[300010], dp[300010];
vector<int> xs;
pii bus[100010];
vector<int> vec[300010];

int main(){
    scanf("%d %d", &n, &m);
    xs.pb(0); xs.pb(n);

    rep(i, m){
	scanf("%d %d", &bus[i].fi, &bus[i].se);
	xs.pb(bus[i].fi); xs.pb(bus[i].se); xs.pb(bus[i].se - 1);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    
    rep(i, m){
	int l = lower_bound(xs.begin(), xs.end(), bus[i].fi) - xs.begin();
	int r = lower_bound(xs.begin(), xs.end(), bus[i].se) - xs.begin();
	vec[r].pb(l);
    }

    dp[0] = 1;
    acc[1] = 1;

    rep(i, xs.size()){
	rep(j, vec[i].size()){
	    dp[i] = (dp[i] + acc[i] - acc[vec[i][j]] + MOD) % MOD;
	    //cout << vec[i][j] << " " << i << endl;
	}
	acc[i+1] = (acc[i] + dp[i]) % MOD;
	//cout << "dp:" << i << " " << dp[i] << endl;
    }
    printf("%I64d\n", dp[xs.size()-1]);
    return 0;
}