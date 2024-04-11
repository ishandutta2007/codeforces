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

ll l, r;

ll calc(ll x){
    if(x == 0) return 0;
    vector<int> v;

    ll dx = x;
    while(dx > 0){
	v.pb(dx % 10);
	dx /= 10;
    }
    reverse(v.begin(), v.end());
    if(v.size() == 1) return x;
    //cout << v.size() << endl;

    ll s = 0;
    for(int i = 1; i < v.size(); ++i){
	for(int j = 1; j <= 9; ++j){
	    ll k = 1;
	    rep(l, i - 2) k *= 10;
	    s += k;
	}
    }

    //cout << s << endl;
    for(int i = 1; i < v[0]; ++i){
	ll k = 1;
	rep(l, (int)v.size() - 2) k *= 10;
	s += k;
    }

    //cout << s << endl;
    if(v.back() >= v[0]) ++s;

    ll k = 0;
    for(int i = 1; i < (int)v.size() - 1; ++i) k = k * 10 + v[i];
    //cout << k << " " << s + k << endl;

    s += k;

    //puts("");
    return s;
}

int main(){
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << endl;
    return 0;
}