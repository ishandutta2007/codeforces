#include <iostream>
using namespace std;
typedef long long LL;

LL la,lb,ta;
LL ra,rb,tb;

LL gcd(LL x,LL y){
    return y==0?x:gcd(y,x%y);
}

LL solve() {
    LL ans = 0;
    LL g = gcd(ta,tb);

    la += ta * 1e9;
    ra += ta * 1e9;
    if(la>=lb) {
        LL k = (la-lb)/g;
        la -= k*g;
        ra -= k*g;
        //printf("%lld %lld %lld %lld\n", la,ra,lb,rb);
        ans = min(ra,rb) - la + 1;
    }
    return ans;
}

int main(){
    cin>>la>>ra>>ta;
    cin>>lb>>rb>>tb;
    if(ta>tb) {
        swap(ta,tb);
        swap(la,lb);
        swap(ra,rb);
    }
    LL ans = 0;
    ans = max(ans,solve());
    la = 1e9 - la; ra = 1e9 - ra; swap(la,ra);
    lb = 1e9 - lb; rb = 1e9 - rb; swap(lb,rb);
    ans = max(ans,solve());
    cout << ans << endl;
}