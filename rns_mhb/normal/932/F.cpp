#include <bits/stdc++.h>
using namespace std;

#define N 100005

typedef long long ll;

const ll INF = 1e18;
template <class T> void chkmin(T &a, T b) { if (a > b) a = b; }

int n;
int a[N], b[N];
vector<int> v[N], w[N];
int timp;
int ver[N], dt[N], ft[N], sz[N], hson[N], h[N];
ll dp[N];

int cnt;
struct convex_hull_trick {
    struct Line{
	   int a;
	   long long b;
	   long long val;
	   double xLeft;
	   bool type;
	   Line(long long _a = 0 , long long _b = 0){
		  a = _a;
		  b = _b;
		  xLeft = -2*(1e18);
		  type = 0;
		  val = 0;
	   }
	   long long valueAt(int x) const{
		  return 1LL * a * x + b;
	   }
	   friend bool areParallel(const Line &l1, const Line &l2){
		  return l1.a == l2.a;
	   }
	   friend double intersectX(const Line &l1 , const Line &l2){
		  return areParallel(l1 , l2) ? 2*(1e18) : 1.0 * (l2.b - l1.b) / (l1.a - l2.a);
	   }
	   bool operator < (const Line &l2) const{
		  if(!l2.type)
			 return a < l2.a;
		  return xLeft > l2.val;
	   }
    };
    set < Line >  hull;
    void init(){
    	hull.clear();
    }
    bool hasPrev(set < Line > :: iterator it){
	   return it != hull.begin();
    }
    bool hasNext(set < Line > :: iterator it){
	   return it != hull.end() && next(it) != hull.end();
    }
    bool irrelevant(const Line &l1 , const Line &l2 , const Line &l3){
	   return intersectX(l1,l3) <= intersectX(l1,l2);
    }
    bool irrelevant(set < Line > :: iterator it){
	   return hasPrev(it) && hasNext(it) && (irrelevant(*next(it) , *it , *prev(it)));
    }
    set < Line > :: iterator updateLeftBorder(set < Line > :: iterator it){
	   if(!hasNext(it)){
		  return it;
	   }
	   double val = intersectX(*it , *next(it));
	   Line buf(*it);
	   it = hull.erase(it);
	   buf.xLeft = val;
	   it = hull.insert(it, buf);
	   return it;
    }
    void addLine(int a , long long b){
	   Line l3 = Line(a, b);
	   auto it = hull.lower_bound(l3);
	   if(it != hull.end() && areParallel(*it , l3)){
		  if(it -> b > b){
			 it = hull.erase(it);
		  }
		  else{
			 return;
		  }
	   }
	   it = hull.insert(it, l3);
	   if(irrelevant(it)){
		  hull.erase(it);
		  return;
	   }
	   while(hasPrev(it) && irrelevant(prev(it))){
		  hull.erase(prev(it));
	   }
	   while(hasNext(it) && irrelevant(next(it))){
		  hull.erase(next(it));
	   }
	   it = updateLeftBorder(it);
	   if(hasPrev(it)){
		  updateLeftBorder(prev(it));
	   }
	   if(hasNext(it)){
		  updateLeftBorder(next(it));
	   }
    }
    long long query(int x){
	   Line q;
	   q.val = x;
	   q.type = 1;
	   auto bestLine = hull.lower_bound(q);
	   if(bestLine == hull.end()){
		  return 2*(1e18);
	   }
	   return bestLine -> valueAt(x);
    }
} cht;

void dfs(int x, int par) {
//    cout<<x<<endl;
    dt[x] = ++timp;
    ver[timp] = x;
    int mx = -1;
    sz[x] = 1;
    for (int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if (y == par) continue;
        w[x].push_back(y);
        dfs(y, x);
        if (mx < sz[y]) mx = sz[y], hson[x] = y;
        sz[x] += sz[y];
    }
    ft[x] = timp;
}

void dsu(int x, bool keep) {
//    cout<<x<<" "<<keep<<endl;
//    assert(0);
//    cout<<x<<endl;
    for (int i = 0; i < w[x].size(); i ++) {
        int y = w[x][i];
        if (y == hson[x]) continue;
        dsu(y, 0);
    }
    if (hson[x] != -1) {
        dsu(hson[x], 1);
    }
    dp[x] = INF;
    for (int i = 0; i < w[x].size(); i ++) {
        int y = w[x][i];
        if (y == hson[x]) continue;
        for (int j = dt[y]; j <= ft[y]; j ++) {
            int jj = ver[j];
            chkmin(dp[x], dp[jj] + 1ll * b[jj] * a[x]);
        }
    }
//    if (x == 1) cout <<dp[x]<<endl;
    chkmin(dp[x], cht.query(a[x]));
    if (dt[x] == ft[x]) dp[x] = 0;
    cht.addLine(b[x], dp[x]);
//    cout<<b[x]<<dp[x]<<endl;
    for (int i = 0; i < w[x].size(); i ++) {
        int y = w[x][i];
        if (y == hson[x]) continue;
        for (int j = dt[y]; j <= ft[y]; j ++) {
            int jj = ver[j];
            cht.addLine(b[jj], dp[jj]);
        }
    }
    if (!keep) {
        cht.init();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(hson, -1, sizeof hson);
    dfs(1, 0);
    dsu(1, 1);
//    for (int i = 1; i <= n; i ++) cout<<dt[i]<<" "<<hson[i]<<endl;
    for (int i = 1; i <= n; i ++) printf("%I64d ", dp[i]);
    return 0;
}