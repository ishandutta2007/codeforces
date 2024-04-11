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
ll l, r;

vector<int> enc(ll x){
    vector<int> a;
    while(x > 0){
	a.pb(x & 1);
	x >>= 1;
    }
    reverse(a.begin(), a.end());
    //rep(i, a.size()) cout << a[i] << " ";
    //cout << endl;
    return a;
}

int main(){
    cin >> n;

    while(n--){
	ll l, r;
	cin >> l >> r;
	vector<int> t1, t2;
	t1 = enc(l); t2 = enc(r);

	if(t1.size() != t2.size()){
	    bool f = true;
	    rep(i, t2.size()) if(t2[i] == 0) f = false;
	    if(f) cout << r << "\n";
	    else{
		ll x = 1;
		rep(i, (int)t2.size() - 1) x *= 2LL;
		--x;
		cout << x << "\n";
	    }
	}else{

	    ll x = 0;
	    int i = 0;

	    for(; i < t1.size(); ++i){
		x *= 2LL;
		if(t1[i] == t2[i]){
		    x += t1[i];
		}else break;
	    }

	    for(int j = i + 1; j < t1.size(); ++j) x *= 2LL;
	    //cout << x << " " << i << endl;

	    bool f = true;
	    for(int j = i; j < t1.size(); ++j) if(t2[j] == 0) f = false;
	    ll ad = 1;

	    if(f){
		for(int j = i; j < t1.size(); ++j) ad *= 2LL;
		--ad;
		x += ad;
	    }else{
		for(int j = i + 1; j < t1.size(); ++j) ad *= 2LL;
		--ad;
		x += ad;
	    }
	    cout << x << "\n";

	}
    }

    return 0;
}