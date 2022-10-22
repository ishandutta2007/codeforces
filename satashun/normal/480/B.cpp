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

int n, l, x, y;
vector<int> vec;

//binary_search(v.begin(), v.end(), 3)

bool a, b;

int main(){
    scanf("%d %d %d %d", &n, &l, &x, &y);
    vec.resize(n);

    rep(i, n) scanf("%d", &vec[i]);
    rep(i, n){
	a |= binary_search(vec.begin(), vec.end(), vec[i] + x);
    	b |= binary_search(vec.begin(), vec.end(), vec[i] + y);
    }

    if(a && b){
	puts("0");
	return 0;
    }

    if(a){
	puts("1");
	printf("%d\n", y);
	return 0;
    }

    if(b){
	puts("1");
	printf("%d\n", x);
	return 0;
    }

    rep(i, n){
	if(binary_search(vec.begin(), vec.end(), vec[i] + x + y)){
	    puts("1");
	    printf("%d\n", vec[i] + x);
	    return 0;
	}

	if(binary_search(vec.begin(), vec.end(), vec[i] + y - x)){
	    if(vec[i] - x >= 0){
		puts("1");
		printf("%d\n", vec[i] - x);
		return 0;
	    }
	    if(vec[i] + y <= l){
		puts("1");
		printf("%d\n", vec[i] + y);
		return 0;
	    }
	}
    }

    puts("2");
    printf("%d %d\n", x, y);

    return 0;
}