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
int ans = INT_MAX;
//int per[10];
ll a[10];
int par[10];
int f[10];
//map<ll, int> m;

int fac(ll x){
    int cnt = 0;
    for(ll i = 2; i * i <= x; ++i){
	while(x % i == 0){
	    x /= i;
	    ++cnt;
	}
    }
    if(x > 1) ++cnt;
    return cnt;
}

int calc(){
    ll x;
    int ret = n;

    int k = 0;
    rep(i, n) if(par[i] == -1) ++k;
    ret += k > 1;

    rep(i, n){
	x = a[i];
	rep(j, n) if(par[j] == i){
	    if(x % a[j] > 0) return INT_MAX;
	    x /= a[j];
	}
	if(f[i] == 1) continue;
	ret += f[i];
	rep(j, n) if(par[j] == i) ret -= f[j];
	if(ret > ans) return INT_MAX;
    }
    return ret;
}

int main(){
    cin >> n;
    rep(i, n){
	cin >> a[i];
	//f[i] = fac(a[i]);
	//m[a[i]] = fac(a[i]);
    }
    sort(a, a + n, greater<ll>());
    rep(i, n) f[i] = fac(a[i]);

    int now = 1;
    rep(i, n) now *= n;
    rep(i, now){
	int bit = i;
	bool f = false;
	rep(j, n){
	    int am = bit % n;
	    par[j] = am == j ? -1 : am;
	    if(par[j] > j){
		f = true;
		break;
	    }
	    bit /= n;
	}
	if(f) continue;
	ans = min(ans, calc());
    }


    /*
    rep(i, n) per[i] = i;

    do{
	vector<ll> v;
	int ret = 0;
	rep(i, n){
	    vector<ll> nv;
	    reverse(v.begin(), v.end());
	    bool f = false;
	    rep(j, v.size()){
		if(!f && v[j] % a[per[i]] == 0){
		    f = true;
		    nv.pb(a[per[i]]);
		    ++ret;
		    if(v[j] / a[per[i]] != 1){
			nv.pb(v[j] / a[per[i]]);
		    }
		}else{
		    nv.pb(v[j]);
		}
	    }
	    if(!f){
		nv.pb(a[per[i]]);
		ret += m[a[per[i]]] + 1; 
	    }
	    v = nv;
	    
	    if(per[0] == 1 && per[1] == 2 && per[2] == 3){
		//rep(i, v.size()) cout << v[i] << ' ';
		//cout << ret << endl;
	    }
	    
	}
	//rep(i, v.size()) cout << v[i] << ' ';
	
	rep(i, v.size()){
	    if(m.count(v[i])){
		ret += (m[v[i]] > 0);
	    }else{
		m[v[i]] = fac(v[i]);
		ret += (m[v[i]] > 0);
	    }
	}

	ans = min(ans, ret + ((int)v.size() > 1));
	//cout << ret + ((int)v.size() > 1) << endl;
    }while(next_permutation(per, per + n));
    */
    cout << ans << endl;
    return 0;
}