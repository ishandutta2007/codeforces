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

int n, ret;
int dp2[1010][1010], dp5[1010][1010];
int d2[1010][1010], d5[1010][1010];
string s;
char ans[2020];
int a[2010][2010];

// 0..down, 1..right

bool f;
int p, q;

int main(){
    scanf("%d", &n);
    rep(i, n + 1) dp2[i][0] = dp2[0][i] = dp5[i][0] = dp5[0][i] = 100000;
    dp2[0][1] = dp2[1][0] = dp5[1][0] = dp5[0][1] = 0;

    rep(i, n){
	rep(j, n){
	    int x;
	    scanf("%d", &x);
	    a[i][j] = x;

	    int a = 0, b = 0;
	    if(x == 0){
		f = true;
		p = i, q = j; 
		a = b = 1;
	    }
	    else{
		while((x & 1) == 0){
		    x >>= 1;
		    ++a;
		}

		while(x % 5 == 0){
		    x /= 5;
		    ++b;
		}
	    }

	    if(dp2[i][j+1] >= dp2[i+1][j]){
		dp2[i+1][j+1] = dp2[i+1][j] + a;
		d2[i+1][j+1] = 1;
	    }else{
		dp2[i+1][j+1] = dp2[i][j+1] + a;
		d2[i+1][j+1] = 0;		
	    }

	    if(dp5[i][j+1] >= dp5[i+1][j]){
		dp5[i+1][j+1] = dp5[i+1][j] + b;
		d5[i+1][j+1] = 1;
	    }else{
		dp5[i+1][j+1] = dp5[i][j+1] + b;
		d5[i+1][j+1] = 0;		
	    }

	}
    }

    if(dp2[n][n] <= dp5[n][n]){
	int i = n, j = n;

	rep(t, (n - 1) * 2){
	    if(d2[i][j]) ans[t] = 'R';
	    else ans[t] = 'D';

	    if(d2[i][j] == 1) --j;
	    else --i;
	}

	ret = dp2[n][n];
    }else{
	int i = n, j = n;

	rep(t, (n - 1) * 2){
	    if(d5[i][j]) ans[t] = 'R';
	    else ans[t] = 'D';

	    if(d5[i][j] == 1) --j;
	    else --i;
	}

	ret = dp5[n][n];
    }
    reverse(ans, ans + (n - 1) * 2);
    

    if(f && ret >= 2){
	printf("1\n");
	rep(i, p){
	    printf("D");
	}
	rep(i, q){
	    printf("R");
	}
	p = n - 1 - p;
	q = n - 1 - q;
	rep(i, p){
	    printf("D");
	}
	rep(i, q){
	    printf("R");
	}
	puts("");
	return 0;
    }

    printf("%d\n", ret);
    printf("%s\n", ans);
    return 0;
}