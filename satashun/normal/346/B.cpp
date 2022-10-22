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

string s, t, ban;
int la, lb, lban;
int fail[110][30];
string dp[110][110][110];
string ans = "";
int l = 0;

int main(){
    cin >> s >> t >> ban;
    la = s.size(); lb = t.size(); lban = ban.size();

    string a = "";
    rep(i, lban + 1){
	if(i > 0) a.pb(ban[i - 1]);
	rep(j, 26){
	    string b = a;
	    b.pb(j + 'A');
	    int mi = min<int>(b.size(), lban);
	    string emp = "";
	    for(int k = 1; k <= mi; ++k){
		emp.pb(ban[k - 1]);
		if(emp == b.substr((int)b.size() - k, k)) fail[i][j] = k;
	    }
	}
    }

    rep(i, la){
	rep(j, lb){
	    if(s[i] == t[j]){
		rep(k, lban){
		    string cur = dp[i][j][k];
		    if(dp[i + 1][j + 1][k].size() < cur.size()) dp[i + 1][j + 1][k] = cur;		    
		    if(cur.size() == 0 && k > 0) continue;
		    if(s[i] == ban[k]){
			dp[i + 1][j + 1][k + 1] = cur + ban[k];
			//cout << dp[i + 1][j + 1][k + 1] << " " << k + 1 << endl;
			//dump(dp[i + 1][j + 1][k + 1]);
			//puts("");
		    }
		    else{
			//cout << "yes" << " " << cur << endl;
			if((int)dp[i + 1][j + 1][fail[k][s[i] - 'A']].size() < (int)cur.size() + 1) dp[i + 1][j + 1][fail[k][s[i] - 'A']] = cur + s[i];
			//dump(dp[i + 1][j + 1][0]);
			//puts("");
		    }
		}
	    }else{
		rep(k, lban){
		    if(dp[i][j + 1][k].size() == 0 && dp[i + 1][j][k].size() == 0) continue;
		    int len = 0;
		    string now = "";

		    if(dp[i][j + 1][k] != ""){
			len = dp[i][j + 1][k].size();
			now = dp[i][j + 1][k];
		    }
		    if(dp[i + 1][j][k] != ""){
			if(dp[i + 1][j][k].size() > len) now = dp[i + 1][j][k];
		    }
		    dp[i + 1][j + 1][k] = now;
		    //cout << "cur " << endl;
		    //cout << now << endl;
		}
	    }
	    //cout << i << " " << j << endl;
	    //rep(k, lban + 1) cout << '(' << dp[i + 1][j + 1][k] << ", " << k << ") ";
	    //cout << endl;
	}
    }

    /*
    rep(i, la + 1){
	rep(j, lb + 1){
	    rep(k, lban){
		if((int)dp[i][j][k].size() > l){
		    l = dp[i][j][k].size();
		    ans = dp[i][j][k];
		}
	    }
	}
    }

    */
    rep(k, lban){
	if((int)dp[la][lb][k].size() > l){
	    l = dp[la][lb][k].size();
	    ans = dp[la][lb][k];
	}
    }

    if(l == 0) cout << "0" << endl;
    else cout << ans << endl;
    
    return 0;
}