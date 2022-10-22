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

int n, m;
double ret = 0.0;
vector<pii> po;
int k;
int ans[10];
int pm[10];

double d(pii a, pii b){
    return sqrt((double)((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se)));
}

int main(){
    cin >> n >> m;

    po.pb(mp(0, 0));
    po.pb(mp(n, m));
    po.pb(mp(0, m));
    po.pb(mp(n, 0));
    if(n != 0){
	po.pb(mp(1, 0));
    }
    if(m != 0){
	po.pb(mp(0, 1));
    }

    if(n != 0){
	po.pb(mp(n-1, m));
    }
    if(m != 0){
	po.pb(mp(n, m-1));
    }
    sort(po.begin(), po.end());
    po.erase(unique(po.begin(), po.end()), po.end());

    k = po.size();
    rep(i, k) pm[i] = i;

    do{
	double t = 0.0;
	rep(i, 3) t += d(po[pm[i]], po[pm[i+1]]);
	if(t > ret){
	    ret = t;
	    rep(i, 4) ans[i] = pm[i];
	}

    }while(next_permutation(pm, pm + k));
    rep(i, 4) cout << po[ans[i]].fi << " " << po[ans[i]].se << endl;
    return 0;
}