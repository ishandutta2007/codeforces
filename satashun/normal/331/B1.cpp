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

int n, q;
int a[300010], pos[300010];
int ans;

bool check(int x, int y){ //can shave [x, y](0-indexed)
    for(int i = x; i < y; ++i) if(pos[i] > pos[i+1]) return false;
    return true;
}

int main(){
    cin >> n;
    rep(i, n){
	cin >> a[i];
	--a[i];
	pos[a[i]] = i;
    }
    cin >> q;
    
    while(q--){
	int t, x, y;
	cin >> t >> x >> y;
	--x; --y;

	if(t == 1){
	    ans = 0;
	    int crt = x;
	    while(true){
		++ans;
		int lb = crt, ub = y + 1;
		while(ub - lb > 1){
		    int mid = (ub + lb) / 2;
		    if(check(crt, mid)) lb = mid;
		    else ub = mid;
		}
		/*
		for(int r = y; r >= crt; --r){
		    if(check(crt, r)){
			crt = r + 1;
			break;
		    }
		}
		*/
		//printf("%d %d\n", lb, ub);
		crt = ub;
		if(crt > y) break;
	    }
	    cout << ans << endl;
	}else if(t == 2){
	    swap(pos[a[x]], pos[a[y]]);
	    swap(a[x], a[y]);
	}
	
    }
    
    return 0;
}