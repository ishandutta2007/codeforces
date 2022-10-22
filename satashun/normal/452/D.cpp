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

int k, n1, n2, n3, t1, t2, t3;
int t;
multiset<pii> s1, s2, s3;

int main(){
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    rep(i, k){
	int nt = t;;
	int add = 0;
	int a1 = 0, a2 = 0, a3 = 0;
	for(auto it = s1.begin(); it != s1.end(); ++it){
	    if(it->fi <= t && it->se > t) ++a1;
	}
	if(a1 + 1 > n1) nt = s1.begin()->fi + t1;

	for(auto it = s2.begin(); it != s2.end(); ++it){
	    if(it->fi <= t + t1 && it->se > t + t1) ++a2;
	}
	if(a2 + 1 > n2) nt = max(nt, s2.begin()->fi - t1 + t2);

	for(auto it = s3.begin(); it != s3.end(); ++it){
	    if(it->fi <= t + t1 + t2 && it->se > t + t1 + t2) ++a3;
	}
	if(a3 + 1 > n3) nt = max(nt, s3.begin()->fi - t1 - t2 + t3);

	
	//t += add;
	t = nt;

	auto it = s1.begin();
	while(it != s1.end() && it->se <= t) s1.erase(it++);
	/*
	for(auto it = s1.begin(); it != s1.end(); ++it){
	    if(it->se <= t + t1){
		s1.erase(it);
	    }else break;
	}
	*/
	it = s2.begin();
	while(it != s2.end() && it->se <= t + t1) s2.erase(it++);	
	it = s3.begin();
	while(it != s3.end() && it->se <= t + t1 + t2) s3.erase(it++);	

	/*
	for(auto it = s2.begin(); it != s2.end(); ++it){
	    if(it->se <= t + t1 + t2){
		s2.erase(it);
	    }else break;
	}
	for(auto it = s3.begin(); it != s3.end(); ++it){
	    if(it->se <= t + t1 + t2 + t3){
		s3.erase(it);
	    }else break;
	}*/

	//printf("%d\n", t);
	s1.insert(mp(t, t + t1));
	s2.insert(mp(t + t1, t + t1 + t2));
	s3.insert(mp(t + t1 + t2, t + t1 + t2 + t3));
    }
    printf("%d\n", t + t1 + t2 + t3);

    return 0;
}