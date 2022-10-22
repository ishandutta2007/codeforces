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

int n;
ll a[300010];
vector<ll> x;
map<ll, int> m;
vector<int> g[300010];
ll ans = LLONG_MIN;
ll dp[300010];
int piv;
vector<int> v;

int main(){
    cin >> n;
    rep(i, n){
	cin >> a[i];
	x.pb(a[i]);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    rep(i, x.size()) m[x[i]] = i;
    rep(i, n) g[m[a[i]]].pb(i);

    rep(i, n) dp[i + 1] = max(dp[i], dp[i] + a[i]);
   

    rep(i, x.size()){
	if(g[i].size() < 2) continue;
	int l = g[i][0];
	int r = g[i][g[i].size() - 1];
	ll ret = dp[r] - dp[l + 1] + x[i] * 2;
	if(ret > ans){
	    ans = ret;
	    piv = i;
	}
    }


    int l = g[piv][0];
    int r = g[piv][g[piv].size() - 1];
    rep(i, l) v.pb(i + 1);
    
    for(int i = l + 1; i < r; ++i){
	if(a[i] < 0) v.pb(i + 1);
    }
    for(int i = r + 1; i < n; ++i) v.pb(i + 1);
    cout << ans << ' ' << v.size() << endl;
    rep(i, v.size()){
	cout << v[i];
	if(i != v.size() - 1) cout << ' ';
	else cout << '\n';
    }
    return 0;
}