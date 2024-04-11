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

bool ispr[10000010];
vector<int> pr;

int n, m;
int v[700010];
int ru[700010];

int main(){
    ispr[0] = ispr[1] = true;
    for(int i = 2; i <= 10000000; ++i){
	if(!ispr[i]){
	    pr.pb(i);
	    for(int j = i * 2; j <= 10000000; j += i){
		ispr[j] = true;
	    }
	}
    }

    scanf("%d", &n);
    rep(i, n){
	int x;
	scanf("%d", &x);
	for(int j = 0; pr[j] * pr[j] <= x; ++j){
	    bool f = false;
	    while(x % pr[j] == 0){
		f = true;
		x /= pr[j];
	    }
	    v[j] += f;
	}

	if(x != 1){
	    int j = lower_bound(pr.begin(), pr.end(), x) - pr.begin();
	    ++v[j];
	}
    }

    rep(i, pr.size()) ru[i+1] = ru[i] + v[i];

    scanf("%d", &m);
    while(m--){
	int l, r;
	scanf("%d %d", &l, &r);
	l = lower_bound(pr.begin(), pr.end(), l) - pr.begin();
	r = upper_bound(pr.begin(), pr.end(), r) - pr.begin();
	printf("%d\n", ru[r] - ru[l]);
    }

    return 0;
}