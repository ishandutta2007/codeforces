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
typedef pair<P, int> PT;
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

int n, w, h;
vector<PT> vec;
int pre[5010], dp[5010];
vector<int> ans;

int main(){
    cin >> n >> w >> h;

    rep(i, n){
	int x, y;
	cin >> x >> y;
	if(w < x && h < y) vec.pb(mp(mp(x, y), i + 1));
    }
    sort(vec.begin(), vec.end());

    if(vec.size() == 0){
	cout << "0" << endl;
	return 0;
    }

    rep(i, vec.size()){
	pre[i] = i;
	dp[i] = 1;

	rep(j, i){
	    if(vec[j].fi.fi != vec[i].fi.fi && vec[j].fi.se < vec[i].fi.se){
		if(dp[j] >= dp[i]){
		    dp[i] = dp[j] + 1;
		    pre[i] = j;
		}
	    }
	}
    }

    int cur = -1, ma = -1;

    rep(i, vec.size()){
	if(dp[i] > ma){
	    ma = dp[i];
	    cur = i;
	}
    }

    while(true){
	ans.pb(vec[cur].se);
	if(cur == pre[cur]) break;
	cur = pre[cur];
    }

    cout << ans.size() << endl;

    for(int i = ans.size() - 1; i >= 0; --i){
	cout << ans[i] << (i == 0 ? '\n' : ' ');
    }

    return 0;
}