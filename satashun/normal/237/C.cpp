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

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int a, b, k;
int ct[1000010];
bool pr[1000010];

bool C(int len){
    bool f = true;
    for(int x = a; x <= b + 1 - len; x++){
	if(ct[x + len - 1] - ct[x - 1] < k){
	    f = false;
	    break;
	}
    }
    return f;
}

int main(){
    pr[0] = pr[1] = true;
    for(int i = 0; i <= 1000000; i++){
	if(!pr[i]){
	    for(int j = i * 2; j <= 1000000; j += i) pr[j] = true;
	}
    }
    for(int i = 2; i <= 1000000; i++){
	if(!pr[i]) ct[i] = ct[i - 1] + 1;
	else ct[i] = ct[i - 1];
    }
    scanf("%d %d %d", &a, &b, &k);
    int lb = 1, ub = b - a + 1;
    if(!C(b - a + 1)) ub = -1;
    else{
	while(ub - lb > 1){
	    int mid = (lb + ub) / 2;
	    if(C(mid)) ub = mid;
	    else lb = mid;
	}
    }
    
    printf("%d\n", ub);
    return 0;
}