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
int a[4010];
vector<int> xs;
short dp[4010][4010];
short ans;
short num[4010];

int main(){
    scanf("%d", &n);
    rep(i, n){
	scanf("%d", &a[i]);
	xs.pb(a[i]);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    rep(i, n){
	a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin();
	++num[a[i]];
    }
    rep(i, xs.size()) ans = max(ans, num[i]);

    set<int> s;

    rep(i, n){
	for(auto x = s.begin(); x != s.end(); ++x){
	    if(*x == a[i]) continue;
	    if(dp[*x][a[i]] < 2) dp[*x][a[i]] = 2;
	    else dp[*x][a[i]] += (dp[*x][a[i]] & 1);
	}


	if(s.find(a[i]) != s.end()){
	    for(auto x = s.begin(); x != s.end(); ++x){
		if(*x == a[i]) continue;
		//if(dp[a[i]][*x] < 2) dp[a[i]][*x] = 2;
		//else dp[a[i]][*x] += ((dp[a[i]][*x] & 1) == 0);
		if(dp[a[i]][*x] >= 2) dp[a[i]][*x] += ((dp[a[i]][*x] & 1) == 0);
	    }
	}

	/*
	rep(i, xs.size()){
	    rep(j, xs.size()){
		//ans = max(ans, dp[i][j]);
		cout << dp[i][j] << " ";
	    }
	    cout << endl;
	}	
	cout << endl;
	*/
	s.insert(a[i]);

    }
    rep(i, xs.size()){
	rep(j, xs.size()){
	    ans = max(ans, dp[i][j]);
	    //cout << dp[i][j] << " ";
	}
	//cout << endl;
    }

    printf("%d\n", (int)ans);
    return 0;
}