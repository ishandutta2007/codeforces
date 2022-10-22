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
typedef long long ll;
typedef pair<ll, ll> pii;

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

pii operator + (const pii a, const pii b){
    return mp(a.fi + b.fi, a.se + b.se);
}

pii operator - (const pii a, const pii b){
    return mp(a.fi - b.fi, a.se - b.se);
}

pii rot(pii a, pii b){ //a ... center: b, rotate pi/2
    pii ve = a - b;
    pii vv = mp(-ve.se, ve.fi);
    return b + vv;
}

ll nor(pii a){ return a.fi * a.fi + a.se * a.se; }
ll dis(pii a, pii b){ return nor(a - b); }

pii p[4], h[4];

bool ok(pii a, pii b, pii c, pii d){
    if(a == b || a == c || a == d || b == c || b == d || c == d) return false;
    pii t[4];
    t[0] = a; t[1] = b; t[2] = c; t[3] = d;
    vector<ll> v;
    rep(i, 4) rep(j, i) v.pb(dis(t[i], t[j]));
    sort(v.begin(), v.end());
    
    return v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[4] == v[5] && v[0] * 2 == v[4];
}

int main(){
    cin >> n;
    while(n--){
	int ma = 20;
	
	rep(i, 4) cin >> p[i].fi >> p[i].se >> h[i].fi >> h[i].se;

	rep(i, 4){
	    rep(j, 4){
		rep(k, 4){
		    rep(l, 4){
			if(ok(p[0], p[1], p[2], p[3])){
			    ma = min(ma, i + j + k + l);
			}
			p[3] = rot(p[3], h[3]);
		    }
		    p[2] = rot(p[2], h[2]);
		}
		p[1] = rot(p[1], h[1]);
	    }
	    p[0] = rot(p[0], h[0]);
	}
	if(ma == 20) puts("-1");
	else cout << ma << endl;
    }
    return 0;
}