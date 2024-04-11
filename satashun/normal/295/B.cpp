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

const int INF = 1e+9;

int n;
ll mat[510][510]; //d[510][510];
int a[510];
ll ans[510];

int main(){
    cin >> n;
    rep(i, n){
	rep(j, n){
	    cin >> mat[i][j];
	}
    }

    rep(i, n){
	scanf("%d", &a[i]);
	--a[i];
    }

    for(int i = n - 1; i >= 0; --i){

	int s = a[i], t, u;
	/*
	for(int j = i; j < n; ++j){
	    t = a[j];
	    mat[s][t] = d[s][t];
	    mat[t][s] = d[t][s];
	}*/

	for(int j = n - 1; j >= 0; --j){
	    t = a[j];
	    for(int k = n - 1; k >= 0; --k){
		u = a[k];
		mat[t][u] = min(mat[t][u], mat[t][s] + mat[s][u]);
	    }
	}

	for(int j = i; j < n; ++j){
	    t = a[j];
	    for(int k = i; k < n; ++k){
		u = a[k];
		ans[i] += mat[t][u];
	    }
	}

	/*
	cout << endl;
	rep(i, n){
	    rep(j, n){
		cout << mat[i][j] << " ";
	    }
	    cout << endl;
	}
	cout << endl;*/
	

    }

    rep(i, n) cout << ans[i] << (i == n - 1 ? '\n' : ' ');

    return 0;
}