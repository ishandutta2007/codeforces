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
typedef long double LD;

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

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

typedef pair<ll, ll> Pll;

int n, m, a, b;
int ansa, ansb;
int lx[100010], rx[100010], le[100010];
long double res;

//long double dis(Pll r, Pll s)  return sqrt((LD)((s.fi - r.fi) * (LD)(s.fi - r.fi) + (s.se - r.se) * (s.se - r.se)));}

int main(){
    res = (LD)1000000000;
    ansa = -1; ansb = -1;
    cin >> n >> m >> a >> b;
    rep(i, n) cin >> lx[i];
    rep(i, m) cin >> rx[i];
    rep(i, m) cin >> le[i];
    rep(i, m){
	int tmp = -1;
	int u;
	long double ide = (long double)rx[i] * (LD)a / (LD)b;
	//cout << ide << endl;
	if(ide <= lx[n-1] || ide >= lx[0]){
	    u = lower_bound(lx, lx + n, ide) - lx;
	    tmp = u;
	    //cout << fabs((long double)lx[u] - ide) <<  fabs((long double)lx[u-1] - ide) << endl;
	    if(u >= 1) if(fabs((long double)lx[u] - ide) > fabs((long double)lx[u-1] - ide)) tmp = u - 1;
	}else if(ide > lx[n-1]){
	    tmp = n - 1;
	}else tmp = 0;
	//printf("%d %d %d %d\n", i, u, u - 1, tmp);
	LD oa = sqrt((LD)((ll)a * (ll)a + (ll)lx[tmp] * (ll)lx[tmp]));
	LD ab = sqrt((LD)((ll)(a - b) * (ll)(a - b) + (ll)(lx[tmp] - (ll)rx[i]) * ((ll)lx[tmp] - (ll)rx[i])));
	LD bl = (LD)le[i];
	LD len = oa + ab + bl;
	//LD len = dis(Pll(0ll, 0ll), Pll((ll)a, (ll)lx[tmp])) + dis((PLL((ll)a, (ll)lx[tmp])), PLL((ll)b, (ll)rx[i])) + (LD)l[i]; 
	if(len < res){
	    res = len;
	    ansa = tmp;
	    ansb = i;
	    //cout << ansa << " " << ansb << endl;
	}
    }
    cout << ansa + 1 << " " << ansb + 1<< endl;
    return 0;
}