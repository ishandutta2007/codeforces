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

//
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

typedef pair<P, int> PT;

int n, m, k;
int cnt;
bool vis[2010][2010];
int d[2010][2010];

int main(){
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
    queue<P> burn;
    rep(i, 2000) fill(d[i], d[i] + 2000, INT_MAX);
    rep(i, k){
	int x, y;
	scanf("%d %d", &x, &y);
	x--; y--;
	burn.push(mp(x, y));
	d[x][y] = 0;
	cnt++;
    }
    while(!burn.empty()){
	P now = burn.front(); burn.pop();
	int x = now.fi;
	int y = now.se;
	if(cnt == n * m) break;
	rep(i, 4){
	    int nx = x + dx[i], ny = y + dy[i];
	     if(nx >= 0 && nx < n && ny >= 0 && ny < m && d[nx][ny] == INT_MAX){
		d[nx][ny] = d[x][y] + 1;
		burn.push(mp(nx, ny));
		cnt++;
	    }
	}
    }
    int ma = 0;
    rep(i, n) rep(j, m) ma = max(ma, d[i][j]);
    rep(i, n){
	rep(j, m){
	    if(d[i][j] == ma){
		printf("%d %d\n", i + 1, j + 1);
		return 0;
	    }
	}
    }
    return 0;
}