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

#define MOD 1000000007LL

int n, k;
ll ans, pro;
ll kai[1010];
ll comb[1010][20];

int perm[11];
bool ok(){
    rep(i, k){
	bool vis[11];
	CLR(vis);
	int now = perm[i];
	if(!i){
	    //if(now == 0) return false;
	    now = perm[now];
	    while(now != 0){
		if(vis[now]) return false;
		vis[now] = true;
		now = perm[now];
	    }
	}
	else{
	    while(now != 0){
		if(vis[now]) return false;
		vis[now] = true;
		now = perm[now];
	    }
	}
    }
    //rep(i, 5) printf("%d%c", perm[i]+1, i == 4 ? '\n' : ' ');
    /*
    for(int i = k; i < n; ++i){
	bool vis[11];
	CLR(vis);	
	int now = perm[i];
	while(1){
	    if(now == 0) return false;
	    if(vis[now]) break;
	    vis[now] = true;
	    now = perm[now];
	}
	//printf("wo\n");
    }*/
    return true;
}

void calc(){
    kai[0] = kai[1] = 1LL;
    for(int i = 2; i <= 1000; ++i){
	kai[i] = kai[i - 1] * (ll)i;
    }
    comb[0][0] = 1;
    for(int i = 1; i < 1010; ++i){
	comb[i][0] = 1;
	if(i < 20) comb[i][i] = 1;
	if(i >= 2){
	    for(int j = 1; j < min(i, 11); ++j){
		comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
	    }
	}
    }
}


ll mod_pow(ll x, ll k, ll mod) {
    ll ret = 1;
    while (k) {
	if (k & 1) ret = ret * x % mod;
	x = x * x % mod;
	k >>= 1;
    }
    return ret;
}

inline void sol(int sz){
    if(sz == k){
	if(ok()) pro++;
	return ;
    }
    rep(i, k){
	perm[sz] = i;
	sol(sz+1);
    }
}

int main(){
    cin >> n >> k;
    /*
    if(k == 1){
	cout << "0" << endl;
	return 0;
    }
    */
    calc();
    
    ans = mod_pow(n - k, n - k, MOD);
    /*
    ll res = 0;
    for(int i = 1; i <= k; ++i){
	ll ret = 0;
	ret = comb[k-1][i-1] * kai[i-1] * mod_pow(k - );
    }*/
    sol(0);
    
    cout << ans * pro  % MOD << endl;
    /*
    for(int i = 1; i < (1 << k); ++i){
	int num = __builtin_popcount(i);
	ll ret = 0; 
	ret = kai[num - 1] * mod_pow(k - num, k - num, MOD) % MOD;
	cout << " " << ret << endl;
	if(num & 1) res += ret;
	else res -= ret;
	cout << res << endl;
    }
    cout << ans * res << endl;
    */
    /*
    ans = 0;
    rep(i, 5){
	rep(j, 5){
	    rep(p, 5){
		rep(q, 5){
		    rep(r, 5){
			perm[0] = i;
			perm[1] = j;
			perm[2] = p;
			perm[3] = q;
			perm[4] = r;
			if(ok()){
			    ans++;
			    printf("%d %d %d %d %d\n", i + 1, j + 1, p + 1, q + 1, r + 1);
			}
		    }
		}
	    }
	}
    }
    rep(i, 7){
	rep(j, 7){
	    rep(p, 7){
		rep(q, 7){
		    rep(r, 7){
			rep(s, 7){
			    rep(t, 7){
				perm[0] = i;
				perm[1] = j;
				perm[2] = p;
				perm[3] = q;
				perm[4] = r;
				perm[5] = s;
				perm[6] = t;
				if(ok()){
				    ans++;
				    printf("%d %d %d %d %d %d %d\n", i + 1, j + 1, p + 1, q + 1, r + 1, s + 1, t + 1);
				}
			    }
			}
		    }
		}
	    }
	}
    }
    cout << ans << endl;
    
    rep(i, n) perm[i] = i + 1;
    do{

    }while(next_permutation(perm, perm + n));
    */
    return 0;
}