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

ll f[110];
int k, x, n, m;

string mk(int a, int b, int num, int l){
    string ret = "";
    if(l == 1){
	if(num > 0 || a != b) return "";
	if(a == 0) ret += "A";
	else if(a == 1) ret += "C";
	else ret += "B";
	return ret;
    }

    if(num * 2 == l){
	if(a == 0 && b == 1){
	    rep(i, num) ret += "AC";
	    return ret;
	}else return ret;
    }

    if(num * 2 == l - 1){
	if(a != 0 && b != 1) return ret;
	if(a != 0){
	    if(b != 1) return ret;
	    if(a == 2) ret = "B";
	    else if(a == 1) ret = "C";
	 
	    rep(i, num) ret += "AC";
	    return ret;
	}else if(b != 1){
	    if(a != 0) return ret;
	    rep(i, num) ret += "AC";
	    if(b == 0) ret += "A";
	    else if(b == 2) ret += "B";
	    return ret;
	}

	rep(i, num) ret += "AC";
	ret += "C";
	return ret;
    }

    if(a == 0) ret += "A";
    else if(a == 1) ret += "C";
    else ret += "B";
    
    rep(i, num) ret += "AC";
    l -= (2 * num + 1);
    rep(i, l - 1) ret += "B";

    if(b == 0) ret += "A";
    else if(b == 1) ret += "C";
    else ret += "B";

    if(num == 0 && ret == "AC") return "";
    return ret;
}

bool simu(int i, int j, int a, int b){
    P lr[110];
    ll ad[110];
    ad[0] = ad[1] = 0LL;
    lr[0].fi = i;
    lr[0].se = j;
    lr[1].fi = a;
    lr[1].se = b;

    for(int t = 2; t <= k; ++t){
	lr[t].fi = lr[t-2].fi;
	lr[t].se = lr[t-1].se;
	ad[t] = ad[t-1] + ad[t-2];
	if(lr[t-2].se == 0 && lr[t-1].fi == 1) ++ad[t];
    }
    
    if(ad[k-1] > x) return false;

    for(int l = 0; l <= n / 2; ++l){
	for(int r = 0; r <= m / 2; ++r){
	    ll now = f[k - 3] * l + f[k - 2] * r + ad[k - 1];
	    if(now != x) continue;
	    string s = mk(i, j, l, n), t = mk(a, b, r, m);
	    if(s == "" || t == "") continue;
	    //cout << i << " " << j << " " << a << " " << b << " " << l << " "<< r << endl;
	    cout << s << endl;
	    cout << t << endl;
	    return true;
	}
    }
    return false;
}

int main(){
    cin >> k >> x >> n >> m;
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i <= 100; ++i) f[i] = f[i-2] + f[i-1];

    bool s = false;

    rep(i, 3){
	rep(j, 3){
	    rep(a, 3){
		rep(b, 3){
		    s |= simu(i, j, a, b);
		    if(s) return 0;
		}
	    }
	}
    }
    cout << "Happy new year!\n";
    return 0;
}