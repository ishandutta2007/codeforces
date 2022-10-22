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
inline int toLL(string s) {long long v; istringstream sin(s);sin>>v;return v;}
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
const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,1,-1};

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int n;
int sr, sc, tr, tc;
int a[110];
int d[110][100010];

int bfs(){
    queue<P> que;
    rep(i, 110){
	rep(j, 100010){
	    d[i][j] = INT_MAX;
	}
    }
    que.push(P(sr, sc));
    d[sr][sc] = 0;

    while(!que.empty()){
	P p = que.front(); que.pop();
	if(p.fi == tr && p.se == tc) break;
	rep(i, 4){
	    int nr = p.fi + dr[i], nc = p.se + dc[i];

	    if(nr == 0) nr = 1;
	    if(nr > n) nr = n;
	    if(nc == 0) nc = 1;
	    if(nc > a[nr]) nc = a[nr];
	    if(d[nr][nc] == INT_MAX){
		d[nr][nc] = d[p.fi][p.se] + 1;
		que.push(P(nr, nc));
	    }
	}
    }
    return d[tr][tc];
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    rep(i, n){
	cin >> a[i+1];
	a[i+1]++;
    }
    cin >> sr >> sc >> tr >> tc;
    cout << bfs() << endl;
    return 0;
}