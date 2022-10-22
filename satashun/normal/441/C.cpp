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
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int n, m, k;
bool vis[310][310];
vector<int> r;

int main(){
    cin >> n >> m >> k;

    int y = 0, x = 0;
    rep(i, k - 1){
	cout << "2 " << y + 1 << " " << x + 1 << " ";
	vis[y][x] = true;

	rep(t, 4){
	    int ny = y + dy[t], nx = x + dx[t];
	    if(ny >= 0 && nx >= 0 && ny < n && nx < m && !vis[ny][nx]){
		y = ny;
		x = nx;
		vis[y][x] = true;
		cout << y + 1 << " " << x + 1 << "\n";
		break;
	    }
	}

	rep(t, 4){
	    int ny = y + dy[t], nx = x + dx[t];
	    if(ny >= 0 && nx >= 0 && ny < n && nx < m && !vis[ny][nx]){
		y = ny;
		x = nx;
		break;
	    }
	}
    }

    int ret = 1;
    while(true){
	r.pb(y + 1);
	r.pb(x + 1);
	vis[y][x] = true;
	bool f = false;

	rep(t, 4){
	    int ny = y + dy[t], nx = x + dx[t];
	    if(ny >= 0 && nx >= 0 && ny < n && nx < m && !vis[ny][nx]){
		y = ny;
		x = nx;
		vis[y][x] = true;
		f = true;
		++ret;
		break;
	    }
	}
	if(!f) break;
    }
    cout << ret << " ";
    rep(t, r.size()) cout << r[t] << (t == (int)r.size() - 1 ? '\n' : ' ');
    return 0;

    /*
    if(m & 1){
	int y = 0, x = 0;
	rep(i, k - 1){
	    if(x >= m){
		++y;
		x = 0;
	    }
	    if((y & 1) == 0 && x == m - 1 && y + 1 < n){
		vis[y][x] = vis[y+1][x] = true;
		cout << "2 " << y + 1 << " " << x + 1 << " " << y + 2 << " " << x + 1 << "\n";		
	    }else{
		vis[y][x] = vis[y][x+1] = true;
		cout << "2 " << y + 1 << " " << x + 1 << " " << y + 1 << " " << x + 2 << "\n";
		x += 2;
	    }
	}
    }else{
	int y = 0, x = 0;
	rep(i, k - 1){
	    if(x >= m){
		++y;
		x = 0;
	    }
	    vis[y][x] = vis[y][x+1] = true;
	    cout << "2 " << y + 1 << " " << x + 1 << " " << y + 1 << " " << x + 2 << "\n";
	    x += 2;
	}
    }

    int y, x;
    rep(i, n){
	rep(j, m){
	    if(!vis[i][j]){
		y = i;
		x = j;
		int ret = 1;

		while(true){
		    vis[y][x] = true;
		    r.pb(y + 1); r.pb(x + 1);
		    bool f = false;
		    rep(t, 4){
			int ny = y + dy[t], nx = x + dx[t];
			if(ny >= 0 && ny < n && nx >= 0 && nx < m && !vis[ny][nx]){
			    f = true;
			    y = ny;
			    x = nx;
			    ret++;
			}
		    }
		    if(!f) break;
		}
		r.pb(y + 1); r.pb(x + 1);
		cout << ret << " ";
		rep(t, r.size()) cout << r[t] << (t == (int)r.size() - 1 ? '\n' : ' ');
		return 0;
	    }
	}
    }*/
}