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
const int N = 2002;
struct Item {
    int id, deg;
    bool operator < (const Item & o) const {
        if (deg == o.deg)
            return id < o.id;
        return deg < o.deg;
    }
} it[N];

int m, n, d[N], a[N];

vector< pair<int,int> > vec;
int cnt[N];
void solve(int x) {
    vec.clear();
    int id = 0;
    for(int i=1;i<=m;i++) {
        rep(j,1,cnt[i]) {
            it[++id].deg = a[i];
            it[id].id = id;
        }
    }

    sort(d+1,d+1+n);
    for(int i=1;i<=n;i++) {
        printf("%d ", it[i].deg);
    } printf("\n");
    for (int i = 1; i <= n; i ++) {
        int las = n-i+1;
        sort(it+1, it+1+las);
        for(int j=1;j<=las;j++) {
            printf("%d ", it[j].deg);
        }printf("\n");

        for(int j=1;j<=it[las].deg;j++) {
            it[las-j].deg --;
            if (it[las-j].deg == -1) return;
            vec.pb(make_pair(it[las-j].id, it[las].id));
        }
    }    
}




void upd(int x, int k) {
    for(int i=x-1;i>=0;i--) {
        a[i] -= k;
    }
}

int main() {
    rd(m);
    rep(i,1,m) {
        rd(a[i]); 
    }
    n = a[m] + 1;

    int las = 1;
    for (int i=m;i>=1;i--) {
        while(a[las] == 0) las ++;
        

        int t=0;
        for (int k=1;k<=a[las];k++) {
            //printf("%d min %d\n", i, a[las]);

            //printf("%d %d %d\n",n,a[i],t );
            for (int j=n-a[i]+t;j<n;j++) {
                vec.pb(make_pair(n,j));
            }
            t ++;
            n --;
        }
        for (int k=m;k>=las;k--) {
            a[k] -= a[las];
        }
    }

    printf("%d\n", sz(vec));
    for(int i=0;i<sz(vec);i++) {
        printf("%d %d\n", vec[i].first, vec[i].second);
    }
}