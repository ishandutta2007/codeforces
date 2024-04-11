#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef long long LL;
const int N=100000+10;
const int MOD=1e9+7;
LL n,b;
map<LL,int> mp;

int main(){
    cin>>n>>b;
    for(LL i=2;i*i<=b;i++){
        if(b%i==0) {
            while(b%i==0) {
                b/=i, mp[i]++;
            }
        }
    }
    if(b>1) mp[b]++;

    LL ans=2e18;
    for(auto p: mp) {
        //printf("# %lld %d\n", p.first, p.second);
        LL x=p.first;
        LL cnt=0, tmp=x;
        while(tmp<=n) {
            cnt += n/tmp;
            //printf("add = %lld %lld\n", tmp, n/tmp);
            if(tmp >= (n+x-1)/x) break;
            tmp = tmp*x;
        }
       //printf("cnt=%lld\n", cnt);
        ans=min(ans, cnt/p.second);
    }
    if(ans==MOD) ans=0;
    printf("%lld\n",ans);
}