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

int n, q;
int a[100010], now[100010];
double ans;
double dp[100010][110];
double comb[1000010][6];

void init(){
    rep(i, 1000000){
    comb[i][0] = 1;
    rep(j, min(5, i)) comb[i][j + 1] = comb[i - 1][j] + comb[i - 1][j + 1]; 
    }
}

int main(){
    scanf("%d", &n);
    rep(i, n){
    scanf("%d", &a[i]);
    now[i] = a[i];
    dp[i][a[i]] = 1;
    ans += (a[i] == 0);
    }
    init();
    scanf("%d", &q);
    rep(i, q){
    int u, v, k;
    scanf("%d %d %d", &u, &v, &k);
    u--; v--;
    double nt[110] = {0};
    ans -= dp[u][0];
    for(int l = 0; l <= a[u]; l++){
        if(dp[u][l] < 1e-20) continue;
        for(int j = 0; j <= min(k, l); j++){
        nt[l - j] += dp[u][l] * comb[l][j] * comb[now[u] - l][k - j] / comb[now[u]][k];
        }
    }
    rep(j, 110) dp[u][j] = nt[j];
    now[u] -= k;
    now[v] += k;
    ans += dp[u][0];
    printf("%.10lf\n", ans);
    }
    return 0;
}