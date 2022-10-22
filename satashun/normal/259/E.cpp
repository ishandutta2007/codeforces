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

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

#define MOD 1000000007LL

int n, ma;
ll ans = 1;
int s[100010]; //s[i]: i

ll mod_pow(ll k, int n){
    if(!n) return 1LL;
    ll tmp = mod_pow(k, n / 2);
    tmp *= tmp;
    tmp %= MOD;
    if(n & 1) tmp *= k;
    tmp %= MOD;
    return tmp;
}

ll solve(int k){
    vector<int> yaku;
    ll res1 = 1LL;
    ll res2 = 1LL;
    for (int i = 1; i * i <= k; i++){
	if(k % i == 0){
	    yaku.pb(i);
	    if(i * i != k) yaku.pb(k / i);
	}
    }
    sort(yaku.begin(), yaku.end());
    int sz = (int)yaku.size();
    yaku.pb(ma + 1);
    rep(i, sz) res1 = res1 * mod_pow(i + 1, s[yaku[i + 1]] - s[yaku[i]]) % MOD; 
    yaku[sz - 1] = ma + 1;
    rep(i, sz - 1) res2 = res2 * mod_pow(i + 1, s[yaku[i + 1]] - s[yaku[i]]) % MOD; //klcm != k
    return (res1 - res2 + MOD) % MOD;
}

int main(){
    scanf("%d", &n);
    rep(i, n){
	int a;
	scanf("%d", &a);
	s[a+1]++;
	ma = max(ma, a);
    }
    rep(i, ma + 1) s[i + 1] += s[i];
    for (int i = 2; i <= ma; i++) ans = (ans + solve(i)) % MOD;
    cout << ans << endl;
    return 0;
}