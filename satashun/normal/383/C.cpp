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

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const int SZ = (1 << 19);
int n, m, now, sz = 1;
int a[200010];
int em[200010], ex[200010];
int vs[400020];
vector<int> g[200010];

struct segtree{
    ll data[SZ * 2], datb[SZ * 2];
    segtree(){ CLR(data); CLR(datb); }

    void add(int a, int b, int x, int id = 0, int l = 0, int r = sz){
	if(r <= a || b <= l) return ;
	if(a <= l && r <= b){
	    data[id] += x;
	    return ;
	}
	datb[id] += (min(b, r) - max(a, l)) * x;
	add(a, b, x, id * 2 + 1, l, (l + r) / 2);
	add(a, b, x, id * 2 + 2, (l + r) / 2, r);
    }

    ll sum(int a, int b, int id = 0, int l = 0, int r = sz){
	if(r <= a || b <= l) return 0;
	if(a <= l && r <= b) return data[id] * (r - l) + datb[id]; 
	ll ret = (min(b, r) - max(a, l)) * data[id];
	ret += sum(a, b, id * 2 + 1, l, (l + r) / 2);
	ret += sum(a, b, id * 2 + 2, (l + r) / 2, r);
	return ret;
     }
}seg[2];

void dfs(int v, int p, int &k){
    em[v]= k;
    vs[k] = v;
    k++;
    rep(i, g[v].size()){
	int e = g[v][i];
	if(e != p){
	    dfs(e, v, k);
	    vs[k++] = v;
	}
    }
    ex[v] = k;
}

void add(int l, int r, int x){
    seg[l&1].add(l, r, x);
    seg[(l+1)&1].add(l, r, -x);
}

int main(){
    scanf("%d %d", &n, &m);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, n - 1){
	int a, b;
	scanf("%d %d", &a, &b);
	--a; --b;
	g[a].pb(b); g[b].pb(a);
    }
    dfs(0, -1, now);
    while(sz < now) sz *= 2;
    rep(i, n) seg[em[i] & 1].add(em[i], em[i] + 1, a[i]);
    
    rep(i, m){
	int t;
	scanf("%d", &t);
	if(t == 1){
	    int pos, val;
	    scanf("%d %d", &pos, &val);
	    --pos;
	    add(em[pos], ex[pos], val);
	}else{
	    int pos;
	    scanf("%d", &pos);
	    --pos;
	    printf("%I64d\n", seg[em[pos]&1].sum(em[pos], em[pos] + 1));
	}
    }
    return 0;
}