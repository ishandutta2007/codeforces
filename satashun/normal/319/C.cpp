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
ll a[100010], b[100010];
ll dp[100010];
int deq[100010];
int s, t;

ll f(int j, int pos){
    return b[j] * a[pos] + dp[j]; 
}

bool ng(int t1, int t2, int t3){
    double a1 = b[t1], b1 = dp[t1];
    double a2 = b[t2], b2 = dp[t2];
    double a3 = b[t3], b3 = dp[t3];
    return (a2 - a1) * (b3 - b2) >= (b2 - b1) * (a3 - a2);
}

int main(){
    scanf("%d", &n);
    rep(i, n) scanf("%I64d", &a[i]);
    rep(i, n) scanf("%I64d", &b[i]);

    /*
       for(int i = 1; i < n; ++i){
       ll mi = LLONG_MAX;
       rep(j, i) mi = min(mi, b[j] * a[i] + dp[j]);
       dp[i] = mi;
       }*/


    for(int i = 1; i < n; ++i){
	while(s + 1 < t && ng(deq[t - 2], deq[t - 1], i - 1)) --t;
	deq[t++] = i - 1;

	while(s + 1 < t && f(deq[s], i) >= f(deq[s + 1], i)) ++s;
	dp[i] = f(deq[s], i);
    }
    printf("%I64d\n", dp[n-1]);

    return 0;
}