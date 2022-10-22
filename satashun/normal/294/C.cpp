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

#define MOD (1000000007LL)

int n, m;
ll kai[1010];
ll comb[1010][1010];
int b[1010];
ll so[1010];
bool sw[1010];
ll dp[1010];
int now, ct;
ll mem[1010];

void init(){
    kai[0] = kai[1] = 1LL;
    for(ll i = 2; i <= 1000; ++i) kai[i] = kai[i-1] * i % MOD;
    rep(i, 1010){
	comb[i][0] = comb[i][i] = 1LL;
	if(!i) continue;
	for(int j = 1; j < i; ++j){
	    comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
	}
    }
}

inline ll kumi(int v){
    if(mem[v]) return mem[v];
    if(v == 1) return mem[v] = 1LL;
    return mem[v] = kumi(v-1) * 2LL % MOD;
}

int main(){
    cin >> n >> m;
    if(n == m){
	cout << "1" << endl;
	return 0;
    }
    init();
    rep(i, m){
	int a;
	cin >> a;
	sw[a-1] = true;
    }
    int f = 0;
    rep(i, n){
	if(sw[i]){
	    if(!ct && !f) f = 1;
	    if(ct){
		if(!f){
		    f = 1;
		    so[0] = 1LL;
		}
		b[now++] = ct;
	    }
	    ct = 0;
	}else{
	    ct++;
	}
    }
    if(ct){
	so[now] = 1LL;
	b[now++] = ct;
    }
    rep(i, now) if(!so[i]) so[i] = kumi(b[i]); 
    /*
    rep(i, now){
	cout << b[i] << " " << so[i] << endl;
    }
    */
    int sum = 0;
    rep(i, now){
	if(!i){
	    dp[i] = so[i];
	    sum += b[i];
	}else{
	    sum += b[i];
	    dp[i] = dp[i-1] * so[i] % MOD;
	    dp[i] = dp[i] * comb[sum][b[i]] % MOD;
	}
    }
    cout << dp[now-1] << endl; 
    return 0;
}