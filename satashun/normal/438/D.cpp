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

typedef pair<ll, int> pli;
int n, m, sz;
ll a[100010];

struct segtree{
    vector<pli> dat;
    vector<ll> dat1, dat2;


    void init(int n_){
	sz = 1;
	while(sz < n_) sz *= 2;
	dat.resize(sz * 2);
	dat1.resize(sz * 2);
	dat2.resize(sz * 2);	
	rep(i, sz * 2) dat1[i] = dat2[i] = 0;	
	rep(i, sz) dat[i + sz - 1] = mp(LLONG_MIN, i);
    }

    void update(int pos, ll x){
	pos += sz - 1;
	dat[pos].fi = x;

	while(pos > 0){
	    pos = (pos - 1) / 2;
	    dat[pos] = max(dat[pos * 2 + 1], dat[pos * 2 + 2]);
	}
    }

    pli get(int a, int b, int k = 0, int l = 0, int r = sz){
	if(b <= l || r <= a) return mp(LLONG_MIN, -1);
	if(a <= l && r <= b) return dat[k];
	return max(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = sz){
	if(b <= l || r <= a) return ;
	if(a <= l && r <= b) dat1[k] += x;
	else{
	    dat2[k] += (min(b, r) - max(a, l)) * x;
	    add(a, b, x, k * 2 + 1, l, (l + r) / 2);
	    add(a, b, x, k * 2 + 2, (l + r) / 2, r);
	}
    }

    ll sum(int a, int b, int k = 0, int l = 0, int r = sz){
	if(b <= l || r <= a) return 0;
	if(a <= l && r <= b) return dat1[k] * (r - l) + dat2[k];
	else{
	    ll res = (min(b, r) - max(a, l)) * dat1[k];
	    res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
	    res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
	    return res;
	}
    }

};

segtree seg;

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;
    seg.init(n);

    rep(i, n){
	cin >> a[i];
	seg.update(i, a[i]);
	seg.add(i, i + 1, a[i]);
    }

    while(m--){
	int tp, l, r, k;
	ll x;
	cin >> tp;

	if(tp == 1){
	    cin >> l >> r; --l;
	    cout << seg.sum(l, r) << "\n";
	}else if(tp == 2){
	    cin >> l >> r >> x; --l;
	    while(true){
		pli ma = seg.get(l, r);
		if(ma.fi < x) break;
		ll t = ma.fi % x;
		a[ma.se] = t;
		seg.update(ma.se, t);
		seg.add(ma.se, ma.se + 1, t - ma.fi);
	    }
	}else{
	    cin >> k >> x;
	    --k;
	    seg.update(k, x);
	    seg.add(k, k + 1, x - a[k]);
	    a[k] = x;
	}
	/*
	rep(i, n) cout << a[i] << " ";
	cout << endl;
	cout << seg.sum(0, n) << endl;
	cout << seg.get(0, n).fi << endl << endl;
	*/
    }

    return 0;
}