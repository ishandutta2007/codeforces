#include <iostream>
using namespace std;
typedef long long LL;
LL n;
LL ok(LL x){
    LL now = n;
    LL cnt = 0;
    while(now) {
        if (now < x) {
            cnt += now, now = 0;
        } else {
            cnt += x, now -= x;
        }
        now = now - now / 10;
    }
    return 2LL * cnt >= n;
}
int main(){
    cin>>n;
    LL L=0,R=n;
    while(R-L>1){
        LL mid=(L+R)>>1;
        if(ok(mid)){
            R=mid;
        }else{
            L=mid;
        }
    }
    cout<<R<<endl;
}