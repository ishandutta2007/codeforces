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

int a, b;
int p, q, r, s;
vector<pii> u, v;
bool f;

int main(){
    cin >> a >> b;
    if(a > b) swap(a, b);

    for(int i = 1; i < a; ++i){
	for(int j = 1; j < a; ++j){
	    if(i * i + j * j == a * a){
		p = i; q = j;
		u.pb(mp(p, q));
	    }
	}
    }

    for(int i = -b; i < 0; ++i){
	for(int j = 1; j < b; ++j){
	    if(i * i + j * j == b * b){
		r = i; s = j;
		v.pb(mp(r, s));
	    }
	}
    }


    rep(i, u.size()){
	rep(j, v.size()){
	    if(u[i].fi * v[j].fi + u[i].se * v[j].se == 0 && u[i].se != v[j].se){
		cout << "YES" << endl;
		cout << "0 0" << endl;
		cout << u[i].fi << " " << u[i].se << endl;
		cout << v[j].fi << " " << v[j].se << endl;
		return 0;
	    }
	}
    }
    cout << "NO" << endl;
    return 0;
}