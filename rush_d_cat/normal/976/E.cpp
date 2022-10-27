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

#define rd(x) scanf("%lld",&x)
#define prt(x) printf("%d\n", x);
#define prtvec(v) for(int i=0;i<v.size();i++) printf("%d%c", v[i], i==(v.size()-1)?'\n':' ');
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,y,x) for(int i=y;i>=x;i--)
const int N = 200000+10;
LL max(LL x, LL y) {return x<y?y:x;}
LL n,a,b;
LL h[N],d[N];
vector<LL> v;
bool cmp(LL x, LL y) {
    return x>y;
}
int main() {
    rd(n); rd(a); rd(b);
    LL M = 1LL << a;
    LL sum = 0;
    rep(i,1,n) {
        rd(h[i]), rd(d[i]);
        v.pb(h[i]-d[i]);

        sum += d[i];
    }
    sort(v.begin(),v.end(),cmp);

    b = min(n, b);

    if (b == 0) {
        return !printf("%lld\n", sum);
    }

    rep(i,0,b-1) {
        if (v[i] >= 0) sum += v[i];
    }
    
    LL res = sum;
    LL sub = v[b-1];

    rep(i,1,n) {
        LL cur = h[i]-d[i];
        LL tmp;

        if (cur >= sub) {
            tmp = sum - max(cur, 0) + max(h[i]*M - d[i], 0);
        } else {
            tmp = sum - max(sub, 0) + max(h[i]*M - d[i], 0);
        }

        res = max(res, tmp);
    }
    cout << res << endl;


}