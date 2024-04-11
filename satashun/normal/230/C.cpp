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

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int n, m, res;
int dp[110][11010], mv[110][11010];
bool table[110][10010];

int main(){
    scanf("%d %d", &n, &m);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) mv[i][j] = 100000;
    for(int i = 0; i < n; i++){
	getchar();
	int pos = -1;
	for(int j = 0; j < m; j++){
	    char c;
	    scanf("%c", &c);
	    if(c == '1') table[i][j] = 1;
	    else table[i][j] = 0;
	    if(table[i][j]){
		mv[i][j] = 0;
		pos = j;
	    }
	}
	if(pos == -1){
	    res = -1;
	    break;
	}
	int piv = pos;
	for(int j = 0; j < m; j++){
	    if(pos != m - 1){
		mv[i][pos + 1] = min(mv[i][pos] + 1, mv[i][pos + 1]);
		pos++;
	    }else{
		mv[i][0] = min(mv[i][0], mv[i][m - 1] + 1);
		pos = 0;
	    }
	}
	pos = piv;
	for(int j = 0; j < m; j++){
	    if(pos != 0){
		mv[i][pos - 1] = min(mv[i][pos] + 1, mv[i][pos - 1]);
		pos--;
	    }else{
		mv[i][m - 1] = min(mv[i][m - 1], mv[i][0] + 1);
		pos = m - 1;
	    }
	}
    }
    /*
    for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	    printf("%d", table[i][j]);
	}
	printf("\n");
    }
    for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	    printf("%d", mv[i][j]);
	}
	printf("\n");
    }
    */
    if(res != -1){
	for(int i = 0; i < m; i++) dp[0][i] = mv[0][i];
	for(int i = 1; i < n; i++){
	    for(int j = 0; j < m; j++){
		dp[i][j] = dp[i-1][j] + mv[i][j];
	    }
	}






	res = 1000000000;
	for(int i = 0; i < m; i++){
	    if(dp[n-1][i] != -1){
		res = min(res, dp[n-1][i]);
	    }
	}
    }
    printf("%d\n", res);
    return 0;
}