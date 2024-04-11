#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=200000+10;
const LL MOD = 1e9+7;
LL l,r;

LL cac(LL x) {
    LL cnt=1,A=1,B=2; int flag=0;
    LL ans=0;
    while(x) {
        if(x>=cnt){
            if(flag == 0) {
                ans=ans + ((A*2+(cnt-1)*2%MOD)%MOD * (cnt%MOD))%MOD *((MOD+1)/2)%MOD;
                ans=ans % MOD;
                A = (A+2*cnt)%MOD;
            } else {
                ans=ans + ((B*2+(cnt-1)*2%MOD)%MOD * (cnt%MOD))%MOD *((MOD+1)/2)%MOD;
                ans=ans % MOD;
                B = (B+2*cnt)%MOD;
            }
            x -= cnt;
            flag ^= 1;
        } else {
            cnt = x;
            //printf("x = %lld, A = %lld\n", x, A);
            if(flag == 0) {
                ans=ans + ((A*2+(cnt-1)*2%MOD)%MOD * (cnt%MOD))%MOD *((MOD+1)/2)%MOD;
                ans=ans % MOD;
                A = (A+2*cnt)%MOD;
            } else {
                ans=ans + ((B*2+(cnt-1)*2%MOD)%MOD * (cnt%MOD))%MOD *((MOD+1)/2)%MOD;
                ans=ans % MOD;
                B = (B+2*cnt)%MOD;
            }
            break;         
        }
        cnt = cnt * 2;
    }
    return ans;
}
int main(){
    cin>>l>>r;
    LL ans=(cac(r)-cac(l-1)+MOD)%MOD;
    cout<<ans<<endl;
}