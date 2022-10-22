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

char c1[200010], c2[200010];
string s, t;
int l[200010], r[200010];
vector<pair<char, int> > vec;

int main(){
    scanf("%s %s", c1, c2);
    s = c1; t = c2;

    l[0] = 0;
    for(int i = 0; i < s.size(); ++i){
	l[i+1] = l[i];
	if(l[i+1] + 1 <= t.size() && s[i] == t[l[i+1]]) ++l[i+1];
    }

    r[s.size()+1] = 0;
    for(int i = (int)s.size() - 1; i >= 0; --i){
	r[i+1] = r[i+2];
	if(r[i+1] + 1 <= t.size() && s[i] == t[(int)t.size() - r[i+1] - 1]) ++r[i+1];
    }
    r[0] = r[1];

    rep(i, t.size()) vec.pb(mp(t[i], i));
    sort(vec.begin(), vec.end());

    rep(i, s.size() + 2){
//	cout << l[i] << " " << r[i] << endl;
    }

    rep(i, s.size()){
	auto lb = lower_bound(vec.begin(), vec.end(), mp(s[i], (int)t.size() - r[i+2] - 1));
	//cout << (int)t.size() - r[i+2] - 1 << " " << l[i] << endl;
	auto ub = upper_bound(vec.begin(), vec.end(), mp(s[i], l[i]));
	if(ub - lb <= 0){
	    //cout << i << endl;
	    puts("No");
	    return 0;
	}
    }
    puts("Yes");
    return 0;
}