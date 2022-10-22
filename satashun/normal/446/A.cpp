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
int ma;
int a[100010];
vector<pair<pii, int> > vec;
int s, la;
pii v[100010];

int main(){
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);

    if(n == 1){
	puts("1");
	return 0;
    }

    rep(i, n){
	if(i == 0){
	    s = 0;
	    la = a[0];
	}else{
	    if(a[i] > la){
		la = a[i];
	    }else{
		vec.pb(mp(mp(s, i - 1), i - s));
		la = a[i];
		s = i;
	    }
	}
    }
    vec.pb(mp(mp(s, n - 1), n - s));

    rep(i, vec.size()){
	ma = max(ma, vec[i].se);
	for(int j = vec[i].fi.fi; j <= vec[i].fi.se; ++j) v[j] = vec[i].fi;
    }

    rep(i, n){
	if(i == 0) ma = max(ma, v[1].se + 1);
	else if(i == n - 1) ma = max(ma, n - v[n - 2].fi);
	else{
	    if(a[i-1] + 1 < a[i+1]){
		ma = max(ma, v[i+1].se - v[i-1].fi + 1);
	    }
	    ma = max(ma, v[i+1].se - i + 1);
	    ma = max(ma, i - v[i-1].fi + 1);
	}
    }
    /*
    rep(i, (int)vec.size() - 2){
	if(vec[i+1].se == 1 && a[vec[i].fi.se] + 1 < a[vec[i+2].fi.fi]){
	    ma = max(ma, vec[i].se + vec[i+1].se + vec[i+2].se);
	}
    }
    */
    printf("%d\n", ma);
    return 0;
}