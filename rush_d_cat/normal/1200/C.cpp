#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;
LL n,m; int q;
LL gcd(LL x,LL y){
    return y==0?x:gcd(y,x%y);
}
// n,m nm/g mn
int main() {
    scanf("%lld%lld%d",&n,&m,&q);
    LL g=gcd(n,m);
    for(int i=1;i<=q;i++){
        LL sx,sy,es,ey; scanf("%lld%lld%lld%lld",&sx,&sy,&es,&ey);
        vector<LL> v;
        if(sx==1) {
            v.push_back((sy-1) / (n/g));
        } else {
            v.push_back((sy-1) / (m/g));
        }
        if(es==1) {
            v.push_back((ey-1) / (n/g));
        } else {
            v.push_back((ey-1) / (m/g));
        }        
        //printf("%lld %lld\n", v[0], v[1]);
        printf("%s\n", v[0]==v[1] ? "YES" : "NO");
    }
}