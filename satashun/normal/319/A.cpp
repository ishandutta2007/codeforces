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

const ll MOD = 1000000007;

int n, ret;
string s, pe[130];
ll f[220];

string c(int x){
    string tmp = "";
    while(true){
	if(x % 2) tmp.pb('1');
	else tmp.pb('0');
	if(x < 2) break;
	x /= 2;
    }
    //reverse(tmp.begin(), tmp.end());
    int r = n - tmp.size();
    rep(i, r) tmp.pb('0');
    reverse(tmp.begin(), tmp.end());
    cout << tmp << endl;
    return tmp;
}

int bi(string sa){
    //reverse(sa.begin(), sa.end());
    int re = 0;
    rep(i, sa.size()){
	re *= 2;
	re += (sa[i] == '1');
    }
    return re;
}

void gr(){
    rep(i, (1 << n)){
	string t = c(i);
	rep(j, n){
	    if(t[j] != s[j]) pe[i].pb('1');
	    else pe[i].pb('0');
	}
	cout << "www" << pe[i] << endl;
    }
    rep(i, (1 << n)){
	int tmp = 0;
	rep(j, i) if(bi(pe[j]) > bi(pe[i])) ++tmp;
	ret += tmp;
	cout << i << ' ' << tmp << endl;
    }
}

ll calc(int k){
    if(k == 0) return (s[k] == '1');
    ll tmp = calc(k - 1) * 2 % MOD;
    if(s[k] == '0'){
	return tmp;
    }
    tmp += f[k * 2];
    tmp %= MOD;

    return tmp;
}

int main(){
    cin >> s;
    f[0] = 1;
    f[1] = 2;
    for(int i = 2; i < 220; ++i) f[i] = f[i - 1] * 2 % MOD; 
    n = s.size();
    //gr();
    reverse(s.begin(), s.end());
    cout << calc(n - 1) << endl;
    return 0;
}