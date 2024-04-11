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
#define rep(i,n)  FOR(i,0,(int)n)
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

typedef pair<int, pii> DATA;

int n, m, s, e, ret;
int a[100010], b[100010];
vector<int> v[100010];

priority_queue<DATA, vector<DATA>, greater<DATA> > que;
map<pii, int> ma;

vector<pii> vec[310];

int main(){
    scanf("%d %d %d %d", &n, &m, &s, &e);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, m){
	scanf("%d", &b[i]);
	v[b[i]].pb(i);
    }

    que.push(mp(0, mp(-1, -1)));
    vec[0].pb(mp(-1, -1));

    rep(t, 310){
	if(vec[t].size()){
	    ret = t;
	}else break;
	vector<pii> nv;

	int la = 10000000;
	rep(i, vec[t].size() - 1){
	    for(int j = vec[t][i].fi + 1; j <= vec[t][i+1].fi; ++j){
		vector<int>::iterator it = upper_bound(v[a[j]].begin(), v[a[j]].end(), vec[t][i].se);
		if(it == v[a[j]].end() || la < *it) continue;
		nv.pb(mp(j, *it));
		la = *it;
	    }
	}

	for(int j = vec[t][(int)vec[t].size() - 1].fi + 1; j < n; ++j){
	    vector<int>::iterator it = upper_bound(v[a[j]].begin(), v[a[j]].end(), vec[t][(int)vec[t].size() - 1].se);
	    if(it == v[a[j]].end() || la < *it) continue;
	    nv.pb(mp(j, *it));
	    la = *it;
	}

	rep(i, nv.size()){
	    //cout << t  + 1 << " " << nv[i].fi << " " << nv[i].se << endl;
	    if(nv[i].fi + nv[i].se + 2 + e * (t + 1) <= s) vec[t+1].pb(nv[i]);
	}
	//sort(vec[t+1].begin(), vec[t+1].end());
    }

    /*
    
    while(!que.empty()){
	DATA q = que.top(); que.pop();
	pii pos = q.se;
	int val = q.fi;
	if(ma[pos] > val) continue;
	//cout << pos.fi << " " << pos.se << " " << val << endl;

	ret = max(ret, val);

	int pa = pos.fi, pb = pos.se;
	int la = 10000000;
	set<int> ss;

	for(int i = pa + 1; i < n; ++i){
	    vector<int>::iterator it = upper_bound(v[a[i]].begin(), v[a[i]].end(), pb);

	    if(ss.find(a[i]) != ss.end()) continue;
	    if(it == v[a[i]].end() || *it > la){
		ss.insert(a[i]);
		continue;
	    }
	    
	    la = *it;

	    if((val + 1) * e + i + 1 + la + 1 <= s && ma[mp(i, la)] < val + 1){
		ma[mp(i, la)] = val + 1;
		que.push(mp(val + 1, mp(i, la)));
	    }
	}
    }
    */
    printf("%d\n", ret);
    return 0;
}