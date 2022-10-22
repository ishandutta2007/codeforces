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

const int MOD = 100000000;

int n1, n2, k1, k2, ret;
int dp[110][110][11][11];

int main(){
    cin >> n1 >> n2 >> k1 >> k2;
    dp[0][0][0][0] = 0;
    dp[1][0][1][0] = dp[0][1][0][1] = 1;

    for(int i = 0; i <= n1; ++i){
	for(int j = 0; j <= n2; ++j){
	    if(i == 0 && j == 0) continue;
	    for(int p = 0; p <= min(i, k1); ++p){
		if(p < k1 && i < n1){
		    dp[i+1][j][p+1][0] += dp[i][j][p][0];
		    dp[i+1][j][p+1][0] %= MOD;
		}
		if(j < n2){
		    dp[i][j+1][0][1] += dp[i][j][p][0];
		    dp[i][j+1][0][1] %= MOD;
		}

	    }

	    for(int p = 0; p <= min(j, k2); ++p){
		if(p < k2 && j < n2){
		    dp[i][j+1][0][p+1] += dp[i][j][0][p];
		    dp[i][j+1][0][p+1] %= MOD;
		}
		if(i < n1){
		    dp[i+1][j][1][0] += dp[i][j][0][p];
		    dp[i+1][j][1][0] %= MOD;
		}
	    }
	}
    }


    for(int i = 0; i <= min(n1, k1); ++i){
	for(int j = 0; j <= min(n2, k2); ++j){
	    ret = (ret + dp[n1][n2][i][j]) % MOD;
	}
    }

    cout << ret << endl;
    return 0;
}