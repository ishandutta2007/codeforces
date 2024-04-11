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
ll a[1010][1010];
ll r1[1010][1010];
ll r2[1010][1010];
ll r3[1010][1010];
ll r4[1010][1010];
ll ret;

int main(){
    cin >> n >> m;
    rep(i, n){
	rep(j, m){
	    cin >> a[i][j];
	}
    }

    for(int i = 0; i < n; ++i){
	for(int j = 0; j < m; ++j){
	    r1[i][j] = a[i][j];
	    /*
	    if(i) r1[i][j] += r1[i-1][j];
	    if(j) r1[i][j] += r1[i][j-1];
	    if(i && j) r1[i][j] -= r1[i-1][j-1];
	    */
	    
	    ll s = 0;
	    if(i) s = max(s, r1[i-1][j]);
	    if(j) s = max(s, r1[i][j-1]);
	    r1[i][j] = s + a[i][j];
	}
    }

    for(int i = n - 1; i >= 0; --i){
	for(int j = m - 1; j >= 0; --j){
	    /*
	    r2[i][j] = a[i][j];
	    r2[i][j] += r2[i+1][j];
	    r2[i][j] += r2[i][j+1];
	    r2[i][j] -= r2[i+1][j+1];
	    */
	    ll s = 0;
	    s = max(s, r2[i+1][j]);
	    s = max(s, r2[i][j+1]);
	    r2[i][j] = s + a[i][j];

	}
    }

    for(int i = n - 1; i >= 0; --i){
	for(int j = 0; j < m; ++j){
	    /*
	    r3[i][j] = a[i][j];
	    r3[i][j] += r3[i+1][j];
	    if(j) r3[i][j] += r3[i][j-1];
	    if(j) r3[i][j] -= r3[i+1][j-1];
	    */
	    ll s = 0;
	    s = max(s, r3[i+1][j]);
	    if(j) s = max(s, r3[i][j-1]);
	    r3[i][j] = s + a[i][j];	    
	}
    }

    for(int i = 0; i < n; ++i){
	for(int j = m - 1; j >= 0; --j){
	    /*
	    r4[i][j] = a[i][j];
	    if(i) r4[i][j] += r4[i-1][j];
	    r4[i][j] += r4[i][j+1];
	    if(i) r4[i][j] -= r4[i-1][j+1];
	    */
	    ll s = 0;
	    if(i) s = max(s, r4[i-1][j]);
	    s = max(s, r4[i][j+1]);
	    r4[i][j] = s + a[i][j];		    
	}
    }

    for(int i = 1; i < n - 1; ++i){
	for(int j = 1; j < m - 1; ++j){
	    ret = max(ret, r1[i][j-1] + r2[i][j+1] + r3[i+1][j] + r4[i-1][j]);
	    ret = max(ret, r3[i][j-1] + r4[i][j+1] + r2[i+1][j] + r1[i-1][j]);
	}
    }
    cout << ret << endl;

    return 0;
}