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

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int n;
int a[3];

int st[310][310];

int calc(int i, int j){
    if(st[i][j] != -1) return st[i][j];
    int &f = st[i][j];
    f = 0;

    if(i == 0 && j == 0) return f = 0;
    for(int x = 1; x <= 300; ++x){
	if(x <= i) f |= !calc(i-x, j);
	if(x <= j) f |= !calc(i, j - x);
	if(x <= i && x <= j) f |= !calc(i-x, j-x);
    }
    return f;
}

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];

    if(n == 1){
	if(a[0]) puts("BitLGM");
	else puts("BitAryo");
    }else if(n == 3){
	int x = a[0] ^ a[1] ^ a[2];
	if(x) puts("BitLGM");
	else puts("BitAryo");
    }else{
	memset(st, -1, sizeof(st));
	if(calc(a[0], a[1])) puts("BitLGM");
	else puts("BitAryo");
    }
    return 0;
}