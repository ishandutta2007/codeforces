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

int n;
int dp[5010][5010];
int acc[5010];

int main(){
    scanf("%d", &n);
    rep(i, 5010) rep(j, 5010) dp[i][j] = INT_MAX;
    dp[0][0] = 0;

    rep(i, n){
	int x;
	scanf("%d", &x);
	acc[i+1] = acc[i] + x;
    }

    for(int i = 0; i < n; ++i){
/*	
	printf("%d : ", i);
	rep(j, n + 1) printf("%d ", dp[i][j]);
	puts("");	
	*/
	for(int j = n - 1; j >= 0; --j) dp[i][j] = min(dp[i][j], dp[i][j+1]);
	int k = 0;

	for(int j = i + 1; j <= n; ++j){
	    while(dp[i][k + 1] <= acc[j] - acc[i]) ++k;
	    if(dp[i][k] <= acc[j] - acc[i]) dp[j][k+1] = min(dp[j][k+1], acc[j] - acc[i]);
	}
    }
    int k = 0;
    for(int i = 0; i <= n; ++i) if(dp[n][i] != INT_MAX) k = i;
    printf("%d\n", n - k);
    return 0;
}