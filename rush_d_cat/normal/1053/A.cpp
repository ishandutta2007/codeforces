#include <iostream>
#include <set>
#include <vector>
typedef long long LL;
using namespace std;
LL n,m,k;
vector<LL> v,v1,v2;
vector<LL> fac(LL x) {
    vector<LL> ans;
    for(int i=1;i*i<=x;i++) {
        if(x%i==0) {
            ans.push_back(i); 
            ans.push_back(x/i);
        } 
    }
    return ans;
}
LL gcd(LL x, LL y) {
    return y==0?x:gcd(y,x%y);
}
int main() {
    cin>>n>>m>>k;
    if(2LL*n*m%k) return !printf("NO\n");
    LL tot = 2LL*n*m/k;
    v1 = fac(2*n);
    v2 = fac(2*m);
    for(auto x: v1) for(auto y: v2) {
        if (tot % (x*y) == 0) {
            v.push_back(x*y);
        }
    }
    for(int i=0;i<v.size();i++) {
        LL x = v[i];
        LL y = tot / v[i];
        if (x<=n && y<=m) {
            printf("YES\n");
            printf("0 0\n%lld 0\n0 %lld\n",x,y); return 0;
        }
    }
    return !printf("NO\n");
}
// xy = 2nm/k