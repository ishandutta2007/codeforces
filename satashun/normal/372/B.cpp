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

int n, m, q;
char c[50][50];
int r[50][50];
int t[50][50][50][50];
int ans[50][50][50][50];

int main(){
    scanf("%d %d %d", &n, &m, &q);

    rep(i, n){
	scanf("%s", c[i]);
	rep(j, m)
	    r[i+1][j+1] = r[i][j+1] + r[i+1][j] - r[i][j] + (c[i][j] == '1');
    }

    rep(i, n){
	rep(j, m){
	    for(int y = i; y < n; ++y){
		for(int x = j; x < m; ++x){
		    int add = (r[y+1][x+1] - r[i][x+1] - r[y+1][j] + r[i][j] == 0);
		    t[i][j][y+1][x+1] = t[i][j][y][x+1] + t[i][j][y+1][x] - t[i][j][y][x] + add;
		}
	    }
	}
    }

    rep(i, n){
	rep(j, m){ //[?, i, ?, j]
	    for(int y = i; y >= 0; --y){
		for(int x = j; x >= 0; --x){
		    ans[y][x][i][j] = ans[y+1][x][i][j] + ans[y][x+1][i][j] - ans[y+1][x+1][i][j] + t[y][x][i+1][j+1];
		}
	    }
	}
    }

    while(q--){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d); --a; --b; --c; --d;
	printf("%d\n", ans[a][b][c][d]);
    }

    return 0;
}