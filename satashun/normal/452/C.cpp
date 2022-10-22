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
long double p[1010];
/*
double s[1010][1010];
double kei[1010][1010];
*/
long double ret;

int main(){
    scanf("%d %d", &n, &m);
    cout << setprecision(12);
    if(n == 1){
	ret = 1.0;
	cout << ret << endl;
	//printf("%.10Lf\n", ret);
	return 0;
    }
    if(m == 1){
	ret = 1.0 / n;
	cout << ret << endl;
	
//	printf("%.10Lf\n", ret);
	return 0;
    }

    if((n - 1) * m >= n){
	p[0] = 1.0;
	for(int i = 0; i < n; ++i){
	    p[0] = p[0] * (long double)((n - 1) * m - i) / (long double)(n * m - i);
	}
	//printf("%Lf\n", p[0]);

	for(int i = 0; i < min(n, m); ++i){
	    p[i+1] = p[i] * (m - i) * (n - i) / (long double)((n - 1) * m - n + i + 1) / (long double)(i + 1);
	}
    }

    //rep(i, m + 1) printf("%Lf\n", p[i]);

    for(int i = 0; i <= min(n, m); ++i) ret = ret + p[i] * i * i / n;
    //printf("%.10Lf\n", ret);
    cout << ret << endl;

    return 0;
}