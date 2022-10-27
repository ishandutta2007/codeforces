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

const int N=200000+10;
int n, a[N],ans[N],b[N];
int f(int x) {
    if(x==0) return 0;
    int ret=1;
    for(int i=2;i*i<=x;i++) {
        if (x%i==0) {
            int c=0;
            while(x%i==0) {
                x/=i; c++;
            }
            if(c%2==1) {
                ret=ret * i;
            }
        }
    }
    if(x>1) ret*=x;
    return ret;
}

vector<int> v;
int pos[N];
int id(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
int vis[100000+10];
int main() {
    rd(n);
    rep(i,1,n) {
        rd(a[i]);b[i]=a[i];
        int sgn = 1;
        if (a[i] < 0) a[i] = -a[i], sgn = -1;
        a[i] = f(a[i]);
        //printf("%d\n", a[i]);
        if (sgn == -1) a[i] = -a[i];
        v.push_back(a[i]);
    } 
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    rep(i,1,n) {
        pos[i] = id(a[i]);
    }

    for(int i=1;i<=n;i++) {
        int ret = 0;
        bool fg = 0;
        for(int j=i;j<=n;j++) {
            int p = pos[j];
            if (b[j] == 0) fg = 1;
            if(vis[p] != i) {
                ret ++; vis[p] = i;
            }

            if (ret>1 && fg)
                ans[ret-1] ++;
            else
                ans[ret] ++;
        }
    }
    for(int i=1;i<=n;i++) {
        printf("%d ", ans[i]);
    }
}