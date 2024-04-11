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

int n;
string s, t;
int a, b, c;
int p, q, now;

string win(){
    if(p > q) return "First";
    else if(p < q) return "Second";
    else return "Draw";
}

int main(){
    cin >> n >> s >> t;
    rep(i, n * 2){
	if(s[i] == '1' && t[i] == '1') ++a;
	else if(s[i] == '1' && t[i] == '0') ++b;
	else if(s[i] == '0' && t[i] == '1') ++c;
    }
    p = (a + 1) / 2;
    q = a - p;
    now = a;
    if(now & 1){
	if(c){
	    --c;
	    ++q;
	    ++now;
	}
	else if(b){
	    --b;
	    ++now;
	}else{
	    cout << win() << endl;
	    return 0;
	}
    }
    while(now < n * 2){
	rep(i, 2){
	    if(i == 0){
		if(b){
		    --b;
		    ++p;
		    ++now;
		}
		else if(c){
		    --c;
		    ++now;
		}else{
		    cout << win() << endl;
		    return 0;
		}
	    }else{
		if(c){
		    --c;
		    ++q;
		    ++now;
		}
		else if(b){
		    --b;
		    ++now;
		}else{
		    cout << win() << endl;
		    return 0;
		}
	    }
	}
    }
    cout << win() << endl;
    return 0;
}