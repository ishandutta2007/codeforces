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

int n, m, p;
int a[200010], b[200010];
map<int, int> ta;
vector<int> v[200010];
vector<int> ret;

int main(){
    scanf("%d %d %d", &n, &m, &p);
    rep(i, n){
	scanf("%d", &a[i]);
	v[i % p].pb(a[i]);
    }
    rep(i, m){
	scanf("%d", &b[i]);
	++ta[b[i]];
    }
   
    rep(i, p){
	if(v[i].size() < m) continue;
	map<int, int> cu = ta;
	int sa = m;
	int s = 0, t = 0;
	for(; t < m; ++t){
	    int num = cu[v[i][t]];
	    if(num > 0) --sa;
	    else ++sa;
	    --cu[v[i][t]];
	}
//	printf("s%d t%d\n", s, t);
//	for(map<int, int>::iterator it = cu.begin(); it != cu.end(); ++it) cout << it->fi << " " << it->se << endl;
	if(sa == 0) ret.pb(i);
	//printf("%d sa : %d\n", t, sa);

	while(t < v[i].size()){
	    int num = cu[v[i][t]];
	    if(num > 0) --sa;
	    else ++sa;
	    --cu[v[i][t]];
	    ++t;

	    num = cu[v[i][s]];
	    if(num < 0) --sa;
	    else ++sa;
	    ++cu[v[i][s]];
	    ++s;
	    if(sa == 0) ret.pb(s * p + i);
	    //for(map<int, int>::iterator it = cu.begin(); it != cu.end(); ++it) cout << it->fi << " " << it->se << endl;
	    //printf("s%d t%d sa : %d\n", s, t, sa);
	}
    }

    sort(ret.begin(), ret.end());
    printf("%d\n", (int)ret.size());
    rep(i, ret.size()){
	printf("%d", ret[i] + 1);
	if(i == (int)ret.size() - 1) puts("");
	else printf(" ");
    }
    return 0;
}