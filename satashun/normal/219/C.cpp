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

int n, k, ret;
string s;
char ans[500010];

int main(){
    cin >> n >> k >> s;
    int cur = 0;
    char c = ' ';

    if(k == 2){
	string t1, t2;
	rep(i, s.size()){
	    t1.pb('A' + (i & 1));
	    t2.pb('A' + ((i + 1) & 1));
	}
	int r1 = 0, r2 = 0;
	rep(i, s.size()){
	    r1 += s[i] != t1[i];
	    r2 += s[i] != t2[i];
	}
	if(r1 < r2){
	    cout << r1 << endl << t1 << endl;
	}else{
	    cout << r2 << endl << t2 << endl;	    
	}
	return 0;
    }

    rep(i, s.size()){
	char g = s[i];

	if(s[i] != c){
	    c = s[i];
	    cur = 1;
	}else{
	    ++cur;
	    if((cur & 1) == 0){
		rep(j, k){
		    if(s[i] != j + 'A' && (i == s.size() - 1 || (i < s.size() - 1 && j + 'A' != s[i+1]))) g = j + 'A';
		}
		ret++;
	    }
	}
	ans[i] = g;
    }
    cout << ret << endl;
    cout << ans << endl;
    return 0;
}