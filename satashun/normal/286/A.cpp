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
int per[100010];
bool vis[100010], used[100010];
bool ok = true;

void recur(int pos, int num){
    if(vis[pos]) return ;
    vis[pos] = true;
    per[pos] = num;
    recur(num, n + 1 - pos);
}

int main(){
    cin >> n;
    if(n == 1){
	printf("1\n");
	return 0;
    }else if(n % 4 == 2 || n % 4 == 3){
	printf("-1\n");
	return 0;
    }
    rep(i, n / 2){
	if(!(i & 1)) per[i] = i + 2;
	else per[i] = n + 1 - i;
    }
    if(n & 1) per[(n - 1) / 2] = (n + 1) / 2;
    for(int i = n - 1; i >= 0; --i){
	if(per[i] != 0) break;
	per[i] = n + 1 - per[n - 1 - i];
    }
    rep(i, n) cout << per[i] << (i == n - 1 ? '\n' : ' ');
    /*
    rep(i, n){
	if(vis[i + 1]) continue;
	rep(j, n + 1){
	    if((!(n & 1 && j == (n - 1) / 2) && j == i) || vis[j + 1]) continue;
	    recur(i + 1, j + 1);
	    printf("new\n");
	    break;
	}
    }
    rep(i, n){
	if(used[per[i + 1]]) ok = false;
	used[per[i + 1]] = true;
    }
    if(!ok){
	printf("-1\n");
	return 0;
    }
    rep(i, n) cout << per[i + 1] << (i == n - 1 ? '\n' : ' ');

    int fl[11];
    rep(i, n) fl[i] = i + 1;
    do{
	bool f = true;
	for(int i = 1; i <= n; ++i){
	    if(fl[fl[i - 1] - 1] != n - i + 1){
		f = false;
		break;
	    }
	}
	if(f){
	    printf("ok\n");
	    rep(i, n) printf("%d ", fl[i]);
	    printf("\n");
	}
	//else printf("no\n");
    }while(next_permutation(fl, fl + n));
    */
    return 0;
}