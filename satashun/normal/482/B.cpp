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
int d[32][100010], ac[32][100010];
int l[100010], r[100010], q[100010];
int res[100010];

int main(){
    scanf("%d %d", &n, &m);

    rep(i, m){
	scanf("%d %d %d", &l[i], &r[i], &q[i]);
	++r[i];
	int x = q[i];
	rep(j, 31){
	    if(x & 1){
		++d[j][l[i]];
		--d[j][r[i]];
	    }
	    x /= 2;
	}
    }

    int b = 1;
    rep(i, 31){
	for(int j = 1; j <= n; ++j){
	    d[i][j] += d[i][j-1];
	    if(d[i][j] > 0) res[j-1] |= b;
	}
	b *= 2;
    }

    rep(i, 31){
	for(int j = 1; j <= n; ++j){
	    ac[i][j] = ac[i][j-1] + (d[i][j] > 0);
	}
    }

    rep(i, m){
	int x = q[i];
	rep(j, 31){
	    int a = (ac[j][r[i]-1] - ac[j][l[i]-1]) == (r[i] - l[i]);
	    if(a && !(x & 1)){
		puts("NO");
		return 0;
	    }
	    x /= 2;
	}
    }

    puts("YES");
    rep(i, n) printf("%d%c", res[i], i == n - 1 ? '\n' : ' ');

    return 0;
}