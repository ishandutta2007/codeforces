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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)

const int dx[] = {1,0};
const int dy[] = {0,1};

int n;
int a[310][310];
int dp[2][310][310];

void add(int b, int y1, int x1, int y2, int x2){
    rep(i, 2){
	rep(j, 2){
	    int ny1 = y1 + dy[i];
	    int ny2 = y2 + dy[j];
	    int nx1 = x1 + dx[i];
	    int nx2 = x2 + dx[j];
	    if(ny1 >= n || nx1 >= n) continue;
	    if(ny2 >= n || nx2 >= n) continue;
	    
	    if(ny1 == ny2) dp[b^1][ny1][ny2] = max(dp[b^1][ny1][ny2], dp[b][y1][y2] + a[ny1][nx1]);
	    else dp[b^1][ny1][ny2] = max(dp[b^1][ny1][ny2], dp[b][y1][y2] + a[ny1][nx1] + a[ny2][nx2]);
	}
    }
}

int main(){
    cin >> n;
    rep(i, n) rep(j, n) cin >> a[i][j];

    dp[0][0][0] = a[0][0];

    rep(d, n * 2 - 2){
	rep(i, 310) rep(j, 310) dp[(d+1)&1][i][j] = -10000000;

	for(int r1 = 0; r1 <= d; ++r1){
	    int c1 = d - r1;
	    if(r1 >= n || c1 >= n) continue;

	    for(int r2 = 0; r2 <= d; ++r2){
		int c2 = d - r2;
		if(r2 >= n || c2 >= n) continue;
		add(d & 1, r1, c1, r2, c2);

	    }

	}
    }

    cout << dp[(n * 2 - 2) & 1][n-1][n-1] << endl;

    return 0;
}