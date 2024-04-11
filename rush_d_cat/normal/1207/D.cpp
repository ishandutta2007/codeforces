#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N=300000+10;
typedef long long LL;
int n;
pair<int,int> p[N]; map< pair<int,int>,int > mp;
const LL MOD = 998244353;
LL fac[N],c[N],d[N];
int main() {
    fac[0]=1; for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%MOD;
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].first,&p[i].second);mp[p[i]]++;
        c[p[i].first]++; d[p[i].second]++;
    }
    sort(p+1,p+1+n);
    LL res=fac[n];
    LL ans1=1,ans2=1,ans3=1;
    for(int i=1;i<=n;i++){
        (ans1*=fac[c[i]])%=MOD;
        (ans2*=fac[d[i]])%=MOD;
    }
    LL ans=(ans1+ans2)%MOD;

    bool ok=1;
    for(int i=1;i<n;i++){
        if(p[i].second>p[i+1].second) ok=0;
    }
    if(ok) {
        for(auto p: mp) {
            (ans3 *= fac[p.second]) %= MOD;
        }
        ans=(ans-ans3+MOD)%MOD; ans=(res-ans+MOD)%MOD;
        printf("%lld\n", ans);
    } else {
        ans=(res-ans+MOD)%MOD;
        printf("%lld\n", ans);
    }
}