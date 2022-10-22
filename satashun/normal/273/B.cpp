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
P a[200010];
ll comb[200010][3];
ll m;
ll ret = 1LL;
vector<int> xs;
map<int, int> una;
map<int, int> cnt[200010];

int main(){
    cin >> n;
    rep(i, n) a[i].se = a[n + i].se = i;
    rep(i, n){
	cin >> a[i].fi;
	xs.pb(a[i].fi);
    }
    rep(i, n){
	cin >> a[n + i].fi;
	xs.pb(a[n + i].fi);
    }
    cin >> m;
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());
    rep(i, xs.size()) una[xs[i]] = i;
    rep(i, n * 2) cnt[una[a[i].fi]][a[i].se]++;
    rep(i, 200010){
	comb[i][0] = 1LL;
	comb[i][1] = (ll)i % m;
	comb[i+1][2] = (comb[i][2] + comb[i][1]) % m;
    }
    rep(i, xs.size()){
	int sum = 0;
	foreach(cnt[i], itr) sum += itr->second;
	foreach(cnt[i], itr){
	    ret = ret * comb[sum][itr->second] % m;
	    sum -= itr->second;
	}
    }
    cout << ret << endl;
    return 0;
}