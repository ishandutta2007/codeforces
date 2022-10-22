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

int m;
string s;
vector<int> ok;
int dp[1010][11][11];
int nxt[1010][11][11];

int calc(int k, int prev, int d){
    int &x = dp[k][prev][d], &nx = nxt[k][prev][d];
    if(~dp[k][prev][d]) return dp[k][prev][d];
    if(k == m) return x = 1;

    x = 0;
    for(int cur : ok){
	if(cur == prev) continue;
	if(cur <= d) continue;
	if(cur > d){
	    int c = calc(k + 1, cur, cur - d);
	    if(c == 1){
		x = 1;
		nx = cur;
		
		break;
	    }
	}
    }
    return x;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> s;
    rep(i, 10) if(s[i] == '1') ok.pb(i + 1);
    cin >> m;

    for(int cur : ok){
	if(calc(0, 0, 0)){
	    puts("YES");
	    int now = 0;
	    int s = 0;
	    rep(i, m){
		int p = now;
		now = nxt[i][p][s];
		s = now - s;		
		printf("%d%c", now, i == m - 1 ? '\n' : ' ');
	    }
	    return 0;
	}
    }

    puts("NO");
    return 0;
}