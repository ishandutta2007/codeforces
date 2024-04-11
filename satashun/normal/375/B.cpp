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
char c[5010][5010];
int r[5010][5010];
vector<pii> vec[5010];
int ret;
int cnt[5010];

int main(){
    scanf("%d %d", &n, &m);
    memset(r, -1, sizeof(r));
    rep(i, n){
	scanf("%s", c[i]);
	int st = -1, la = -1;
	rep(j, m){
	    if(c[i][j] == '0'){
		if(st != -1) vec[i].pb(mp(st, la));
		st = -1;
	    }else{
		if(st == -1) st = j;
		la = j;
	    }
	}
	if(st != -1) vec[i].pb(mp(st, la));

	for(pii itl : vec[i]){
	    for(int j = itl.fi; j <= itl.se; ++j) r[i][j] = itl.se;
	}
	/*
	rep(j, m) printf("%d ", r[i][j]);
	puts("");
	*/
    }

    rep(i, m){
	memset(cnt, 0, sizeof(cnt));
	rep(j, n) if(r[j][i] != -1) ++cnt[r[j][i] - i + 1];
	for(int j = m; j >= 0; --j) cnt[j] += cnt[j+1];
	for(int j = 1; j <= m; ++j) ret = max(ret, j * cnt[j]);
    }
    printf("%d\n", ret);
    return 0;
}