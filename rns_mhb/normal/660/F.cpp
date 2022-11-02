#include <bits/stdc++.h>
using namespace std;

#define N 200005

typedef long long ll;
const double INF = 2e18;
template<class T> void chkmax(T &a, T b) { if (a < b) a = b; }

int n;
int a[N];
ll s[N], t[N];
ll ans;

struct convex_hull_trick {
    struct line{
        ll m, b;
        ll val;
        double xLeft;
        bool type;
        line(ll _m = 0, ll _b = 0) {
            m = _m;
            b = _b;
            xLeft = -INF;
            type = 0;
            val = 0;
        }
        ll valueAt(ll x) const {
            return 1ll * m * x + b;
        }
        friend bool areParallel(const line &l1, const line &l2) {
            return l1.m == l2.m;
        }
        friend double intersectX(const line &l1 , const line &l2) {
            return areParallel(l1 , l2) ? INF : 1.0 * (l2.b - l1.b) / (l1.m - l2.m);
        }
        bool operator < (const line &l2) const {
            if(!l2.type) return m < l2.m;
            return xLeft > l2.val;
        }
    } ;
    set<line> hull;
    void init(){
    	hull.clear();
    }
    bool hasPrev(set<line> :: iterator it) {
	   return it != hull.begin();
    }
    bool hasNext(set<line> :: iterator it) {
	   return it != hull.end() && next(it) != hull.end();
    }
    bool irrelevant(const line &l1 , const line &l2 , const line &l3) {
	   return intersectX(l1,l3) <= intersectX(l1,l2);
    }
    bool irrelevant(set < line > :: iterator it) {
	   return hasPrev(it) && hasNext(it) && (irrelevant(*next(it) , *it , *prev(it)));
    }
    set<line> :: iterator updateLeftBorder(set<line> :: iterator it) {
        if(!hasNext(it)) {
            return it;
        }
        double val = intersectX(*it , *next(it));
        line buf(*it);
        it = hull.erase(it);
        buf.xLeft = val;
        it = hull.insert(it, buf);
        return it;
    }
    void add_line(ll m , ll b) {
        line l3 = line(m, b);
        auto it = hull.lower_bound(l3);
        if (it != hull.end() && areParallel(*it , l3)) {
            if(it -> b > b){
                it = hull.erase(it);
            }
            else return;
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
    ll query(ll x){
        line q;
        q.val = x;
        q.type = 1;
        auto bestLine = hull.lower_bound(q);
        if(bestLine == hull.end()){
            return INF;
        }
        return bestLine -> valueAt(x);
    }
} cht;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
        t[i] = t[i-1] + 1ll * i * a[i];
    }
    for (int i = 1; i <= n; i ++) {
        cht.add_line(i - 1, -1ll * (i - 1) * s[i-1] + t[i-1]);
        chkmax(ans, t[i] - cht.query(s[i]));
    }
    printf("%I64d\n", ans);
    return 0;
}