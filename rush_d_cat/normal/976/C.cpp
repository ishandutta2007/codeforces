#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define rd(x) scanf("%d",&x)
#define prt(x) printf("%d\n", x);
#define prtvec(v) for(int i=0;i<v.size();i++) printf("%d%c", v[i], i==(v.size()-1)?'\n':' ');
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,y,x) for(int i=y;i>=x;i--)

const int N=300000+10;
const double EPS = 1e-8;
struct Item {
    int l, r;
    int id;
    bool operator < (const Item & o) const {
        if (l == o.l) return r > o.r;
        return l < o.l;
    }
} it[N];

int n;
int main() {
    rd(n);
    rep(i,1,n) {
        scanf("%d%d",&it[i].l,&it[i].r); it[i].id = i;
    }
    sort(it+1,it+1+n);
    int bst=-1,mx=-1;
    rep(i,1,n) {
        if (mx>=it[i].r) {
            return !printf("%d %d\n", it[i].id, bst);
        }
        mx = it[i].r;
        bst= it[i].id;
    }
    printf("-1 -1\n");
}