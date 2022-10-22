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
typedef long long ll;
typedef pair<ll, int> P;

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

int n, k, sz = 1;
vector<ll> v;
ll a[200010], dp[200010];
P d[200010];
ll ans = -1;

int main(){
    cin >> n >> k;
    rep(i, n){
	cin >> a[i];
	dp[i+1] = dp[i] + a[i];
    }
    rep(i, n) if(i-k+1>=0) v.pb(dp[i+1] - dp[i+1-k]);
    //rep(i, v.size()) cout << v[i] << endl;
    d[v.size()] = mp(v[v.size() - 1], -(v.size() - 1));
    for(int i = v.size() - 2; i >= 0; --i){
	d[i+1] = max(d[i+2], mp(v[i], -i));
	//cout << i << ' ' << d[i+1].fi << endl;
    }
    //rep(i, v.size()) cout << i << ' ' << d[i+1].fi << ' ' << d[i+1].se << endl;
    for(int i = 0; i < v.size(); ++i){
	if(i + k >= v.size()) break;
	ans = max(ans, d[i + k + 1].fi + v[i]);
    }
    //cout << ans << endl;
    rep(i, v.size()){
	if(i + k >= v.size()) break;
	if(ans == d[i+k+1].fi + v[i]){
	    cout << i + 1 << ' ' << -d[i+k+1].se + 1 << endl;
	    return 0;
	}
    }
    return 0;
}