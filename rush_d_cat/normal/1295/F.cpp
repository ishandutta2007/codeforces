#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
LL mpow(LL a, LL x) {
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0) return t*t%MOD;
    return t*t%MOD*a%MOD;
}
LL inv[10002];
LL C(LL A, LL B) {
    LL ans=1;
    for(LL i=A;i>A-B;i--) ans=ans*i%MOD;
    for(LL i=1;i<=B;i++) ans=ans*inv[i]%MOD;
    return ans;
}
LL cac(LL L, LL R, LL k) {
    return C(R-L+k, k);
}
LL gcd(LL x, LL y) {
    return y==0?x:gcd(y,x%y);
}
const int N=202;
LL dp[N][N<<1],w[N][N<<1],l[N],r[N];
int n;
vector<LL> v;
int main() {
    for(int i=0;i<=10000;i++) inv[i]=mpow(i,MOD-2);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&l[n+1-i],&r[n+1-i]);
        v.push_back(l[n+1-i]); v.push_back(r[n+1-i]+1); //v.push_back(r[i]+1); //v.push_back(l[i]-1); v.push_back(r[i]-1);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    memset(dp,0,sizeof(dp));
    memset(w,0,sizeof(w));
    dp[0][0]=0; w[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int x1=0;x1<v.size();x1++) {
            for(int x2=x1+1;x2<v.size();x2++) {
                for(int j=i+1;j<=n;j++){
                    if (! (l[j]<=v[x2-1] && r[j]>=v[x2]-1) ) break;
                    LL ways = cac(v[x2-1],v[x2]-1,j-i) % MOD;
                    (w[j][x2] += w[i][x1] * ways % MOD) %= MOD;
                }
            }
        }
    }
    LL ans=0;
    for(int i=1;i<=v.size();i++) ans=(ans+w[n][i])%MOD;
    
    int cc=0,kk=0;
    for(int i=42;i<=1337;i++)for(int j=13;j<=420;j++){
        if(i<=j) cc++;
        kk++;
    }
    //cout << cc << " " << kk << endl;
    //cout << 578894053LL * kk % MOD << endl;
    LL all=1;
    for(int i=1;i<=n;i++) all = all * (r[i]-l[i]+1) % MOD;
    //cout << ans << " " << all << endl;
    cout<<(long long)ans*mpow(all,MOD-2)%MOD<<endl;
    //cout<<cc*mpow(kk,MOD-2)%MOD<<endl;
    /*
    RES = 0;
    dfs(1,0,0);
    cout << (long long)RES << endl;
    */
}