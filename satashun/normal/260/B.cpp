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

//
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

string s;

const int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ma = -1;
map<string, int> u;

int main(){
    cin >> s;
    int len = s.size();
    for (int i = 2; i < len; i++){
	if(s[i] != '-') continue;
	string y = s.substr(i + 4, 4);
	string d, m;
	if(y != "2013" && y != "2014" && y != "2015") continue;
	bool f = false;
	m = s.substr(i + 1, 2);
	d = s.substr(i - 2, 2);
	if(!(m[0] >= '0' && m[0] <= '9' && m[1] >= '0' && m[1] <= '9')) continue;
	if(!(toInt(m) >= 1 && toInt(m) <= 12)) continue;
	int day = month[toInt(m)];
	if(!(d[0] >= '0' && d[0] <= '9' && d[1] >= '0' && d[1] <= '9')) continue;
	if(!(toInt(d) >= 1 && toInt(d) <= day)) continue;
	//cout << d << " " << m << " " << y << endl;
	string in = d + m + y;
	if(u.find(in) == u.end()) u[in] = 0;
	else u[in]++;
    }
    foreach(u, it){
	ma = max(ma, it->second);
    }
    foreach(u, it){
	if(it->second == ma){
	    string ans = it->first;
	    rep(i, ans.size()){
		cout << ans[i];
		if(i == 1 || i == 3) cout << '-';
		else if(i == ans.size() - 1) cout << endl;
	    }
	    break;
	}
    }
    return 0;
}