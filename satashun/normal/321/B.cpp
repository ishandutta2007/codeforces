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

int n, m, ret;
vector<int> me;
vector<int> a, d;

int calc(int pos){
    multiset<int> s;
    rep(i, me.size()) s.insert(me[i]);

    rep(i, pos){
	auto it = s.upper_bound(d[i]);
	if(it == s.end()) return -1;
	s.erase(it);
    }

    int res = 0;

    for(int i = 0; i <= min(a.size(), s.size()); ++i){
	multiset<int, greater<int> > s1, s2;

	for(auto it = s.begin(); it != s.end(); ++it) s1.insert(*it);
	rep(j, i) s2.insert(a[j]);

	auto it1 = s1.begin(), it2 = s2.begin();
	bool f = true;

	int val = 0;
	//puts("");
	rep(t, i){
	    //cout << *it1 << " " << *it2 << endl;
	    if(*it1 < *it2){
		f = false;
		break;
	    }
	    val += *it1 - *it2;
	    s1.erase(it1++);
	    s2.erase(it2++);
	}
	if(!f) continue;

	if(i == a.size() && pos == d.size()){
	    for(auto it = s1.begin(); it != s1.end(); ++it) val += *it;
	}
	res = max(res, val);
	//cout << val << endl;
    }
    return res;
}

int main(){
    cin >> n >> m;

    rep(i, n){
	string s; int x;
	cin >> s >> x;
	if(s == "ATK") a.pb(x);
	else d.pb(x);
    }
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());

    rep(i, m){
	int x; cin >> x;
	me.pb(x);
    }

    for(int i = 0; i <= d.size(); ++i){
	ret = max(ret, calc(i));
    }

    cout << ret << endl;
    return 0;
}