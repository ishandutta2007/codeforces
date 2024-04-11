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

LL n,k,mx,mn,d;

int main(){
    cin>>n>>k>>mx>>d;
    if (k>(1e18+d-1)/d) {
        mn=1;
    } else {
        mn = n/(k*d+1)+1;
    }
    LL ret = 0;
    ret = max(ret, n/(k*mx)*mx + (n%(k*mx) >= mx ? mx : 0) );
    
    for(int i=1;i<=d;i++) {
        LL R = n / i;
        LL L = n / (i+1)+1;
        // k*x [L,R]
        LL l = (L+k-1) / k;
        LL r = R / k;
        //printf("@ %lld %lld\n", l, r);
        l = max(l, mn); l = min(l, mx);
        r = min(r, mx); r = max(r, mn);
        //printf("%lld %lld\n", l, r);
        
        if (n % (k*r) >= r) {
            ret = max(ret, n/(k*r)*r + r);
        } else {
            ret = max(ret, n/(k*r)*r);
        }

        while (r - l > 1) {
            LL mid = (l+r)>>1;
            if (n % (k*mid) >= mid) {
                l = mid;
            } else {
                r = mid;
            }
        }

        if (n % (k*l) >= l) {
            ret = max(ret, n/(k*l)*l + l);
        } else {
            ret = max(ret, n/(k*l)*l);
        }


    }
    cout << ret << endl;
}