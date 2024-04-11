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
const ll MOD = 1000000007LL;
ll s, za;
vector<ll> v;

ll mul(ll x, ll a){
    ll ret = 1;
    while(a > 0){
	if(a & 1) ret = ret * x % MOD;
	x = x * x % MOD;
	a /= 2;
    }
    return ret;
}

int main(){
    cin >> n >> za;
    rep(i, n){
	ll t;
	cin >> t;
	s += t;
	v.pb(t);
    }
    rep(i, n) v[i] = s - v[i];
    sort(v.begin(), v.end());

    ll ret = v[0], kei = 0LL;
    rep(i, n){
	if(v[i] == ret) kei++;
	else{
	    while(kei > 0 && kei % za == 0 && ret < v[i]){
		kei /= za;
		++ret;
	    }
	    if(ret < v[i]) break;
	    kei++;
	}
    }
    while(kei % za == 0){
	kei /= za;
	++ret;
    }

    cout << mul(za, min(ret, s)) << endl;
    return 0;
}

/*
2 2
2 2

>>8

3 3
1 2 3

>>27

2 2
29 29
 
>>73741817

4 5
0 0 0 0

>>1

*/