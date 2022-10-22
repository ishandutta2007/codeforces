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

const int INF = 1000000;

int n, ret = INF;
bool pri[100];
vector<int> pr;
int dp[110][(1 << 16) + 10];
int c[100];
int pre[110][(1 << 16) + 10];
int val[110][(1 << 16) + 10];

int enc(int x){
    int bit = 0;
    rep(i, pr.size()){
	bit *= 2;
	if(x % pr[i] == 0) bit |= 1;
    }
    return bit;
}

int main(){
    rep(i, 100) pri[i] = true;
    for(int i = 2; i < 59; ++i){
	if(!pri[i]) continue;
	pr.pb(i);
	for(int j = i * 2; j < 59; j += i) pri[j] = false;
    }

    for(int i = 1; i < 59; ++i) c[i] = enc(i);
    

    scanf("%d", &n);
    
    rep(i, n + 1) rep(j, 1 << 16) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i, n){
	int x;
	scanf("%d", &x);
	rep(j, 1 << 16){
	    if(dp[i][j] == INF) continue;
	    for(int k = 1; k < 59; ++k){
		int bit = c[k];
		if((bit & j) == 0){
		    int nb = bit | j;
		    if(dp[i+1][nb] > dp[i][j] + abs(x - k)){
			dp[i+1][nb] = dp[i][j] + abs(x - k);
			val[i+1][nb] = k;
			pre[i+1][nb] = j;
		    }
		}
	    }
	}
    }

    rep(i, 1 << 16) if(dp[n][i] != INF) ret = min(ret, dp[n][i]);
    
    rep(i, 1 << 16) if(dp[n][i] == ret){
	vector<int> ans(n);
	int cur = i;
	for(int j = n; j >= 1; --j){
	    ans[j-1] = val[j][cur];
	    cur = pre[j][cur];
	}
	rep(j, n) printf("%d%c", ans[j], j == n - 1 ? '\n' : ' ');
	return 0;
    }


    //printf("%d\n", *min_element(dp[n], dp[n] + (1 << 16)));
    return 0;
}