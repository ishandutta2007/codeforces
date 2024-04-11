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
const double EPS = 1e-8;

LL n,m,k;
int main() {
    cin>>n>>m>>k;
    if (k<n) {
        return !printf("%lld %lld\n", k+1, 1LL);
    }
    k -= n;
    LL row = n - k / (m-1), col;
    LL res = k % (m-1);
    if (row % 2 == 0) {
        col = 2 + res;
    } else {
        col = m - res;
    }
    printf("%lld %lld\n", row, col);
}