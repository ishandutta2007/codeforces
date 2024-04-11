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

int m;
int a[100010], b[100010], c[100010];
string s;

int main(){
    cin >> s;
    rep(i, s.size()){
	a[i+1] = a[i];
	b[i+1] = b[i];
	c[i+1] = c[i];

	if(s[i] == 'x') a[i+1]++;
	else if(s[i] == 'y') b[i+1]++;
	else c[i+1]++;
    }

    cin >> m;
    rep(i, m){
	int l, r;
	string ret = "";
	cin >> l >> r;
	--l;
	int x, y, z;
	x = a[r] - a[l];
	y = b[r] - b[l];
	z = c[r] - c[l];
	//cout << x << " " << y << " " << z << endl;

	int len = r - l;
	if(len <= 2) ret = "YES";
	else{
	    int gr = len / 3, mo = len % 3;
	    int v[3];
	    v[0] = x;
	    v[1] = z;
	    v[2] = y;
	    //cout << gr << " amari " << mo << endl; 
	    rep(j, 3){
		int d[3];
		rep(k, 3){
		    int po = (j + k) % 3;
		    d[po] = v[k];
		}

		bool f1 = true;
		rep(k, 3){
		    if(gr + (k < mo) != d[k]) f1 = false;
		}
		if(f1) ret = "YES";
	    }
	    if(ret == "") ret = "NO";
	}
	cout << ret << endl;
    }

    return 0;
}