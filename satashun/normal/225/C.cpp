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

int n, m, x, y, ret = INT_MAX;
int dp[1010][2][1010];
int sh[1010];
char b[1010][1010];

int main(){
    scanf("%d %d %d %d", &n, &m, &x, &y);

    rep(i, n){
	scanf("%s", b[i]);
	rep(j, m){
	    sh[j] += b[i][j] == '#';
	}
    }

    rep(i, m + 1) rep(j, 2) rep(k, y + 1) dp[i][j][k] = INT_MAX / 2;
    //dp[0][0][0] = dp[0][1][0] = 0;

    dp[1][0][1] = sh[0];
    dp[1][1][1] = n - sh[0];

    for(int i = 1; i < m; ++i){
	int ad = sh[i];

	for(int j = 2; j <= min(y, i + 1); ++j){
	    dp[i+1][0][j] = min(dp[i+1][0][j], dp[i][0][j-1] + ad);
	}

	for(int j = x; j <= y; ++j) dp[i+1][0][1] = min(dp[i+1][0][1], dp[i][1][j] + ad);

	ad = n - ad; 

	for(int j = 2; j <= min(y, i + 1); ++j){
	    dp[i+1][1][j] = min(dp[i+1][1][j], dp[i][1][j-1] + ad);
	}

	for(int j = x; j <= y; ++j) dp[i+1][1][1] = min(dp[i+1][1][1], dp[i][0][j] + ad);
    }

    for(int i = x; i <= y; ++i){
	ret = min(ret, dp[m][0][i]);
	ret = min(ret, dp[m][1][i]);	
    }

    printf("%d\n", ret);

    return 0;
}