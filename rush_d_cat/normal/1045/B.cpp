#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const int B = 131;
const int N = 200000 + 10;
int n,m,a[N],b[N];
LL s[N][2],p[N],inv[N];
LL mpow(LL a,LL x) {
    if(x==0) return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0) return t*t%MOD;
    return t*t%MOD*a%MOD;
}
int gethash(int l,int r,int on) {
    if(on==0) {
        LL tmp = (s[r][0]-s[l-1][0]+MOD)%MOD;
        return tmp * inv[l-1] % MOD;
    }
    if(on==1) {
        LL tmp = (s[l][1]-s[r+1][1]+MOD)%MOD;
        return tmp * inv[(n+1)-r] % MOD;
    }
}
bool ispal(int l,int r) {
    if(l>r) return 1;
    int mid=(l+r)>>1;
    //printf("ispal %d %d\n", l,r);
    //printf("hash1 = %d, hash2 = %d\n", gethash(l,mid,0), gethash(mid,r,1));
    if((r-l)%2==0) return gethash(l,mid,0) == gethash(mid,r,1);
    return gethash(l,mid,0) == gethash(mid+1,r,1);
}
int main() {
    p[0]=1; for(int i=1;i<N;i++) p[i]=1LL*p[i-1]*B%MOD;
    LL tmp=mpow(B,MOD-2); 
    inv[0]=1;for(int i=1;i<N;i++) inv[i]=inv[i-1]*tmp%MOD;
    scanf("%d%d",&n,&m); 
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    a[n+1] = m;
    for(int i=1;i<=n+1;i++)b[i]=a[i]-a[i-1];
    for(int i=1;i<=n+1;i++)s[i][0]=(s[i-1][0]+p[i-1]*b[i])%MOD;
    for(int i=n+1;i>=1;i--)s[i][1]=(s[i+1][1]+p[n+1-i]*b[i])%MOD;
    //for(int i=1;i<=n+1;i++)printf("s[%d][0]=%d\n", i,s[i][0]);
    //for(int i=n+1;i>=1;i--)printf("s[%d][1]=%d\n", i,s[i][1]);
    vector<int> ans;
    //for(int i=1;i<=n+1;i++) printf("b = %d\n", b[i]); 
    //if(ispal(1,n+1)) ans.push_back(0);
    if(ispal(2,n)) {
        if(b[1]>=b[n+1]) ans.push_back(b[1]-b[n+1]); 
        else ans.push_back(m-(b[n+1]-b[1]));
    }
    for(int i=2;i<=n;i++) {
        if(b[i]==b[1]+b[n+1] && ispal(2,i-1) && ispal(i+1,n)) ans.push_back(a[i]-b[n+1]); 
    }
    printf("%d\n", ans.size()); sort(ans.begin(),ans.end());
    for(auto x: ans) printf("%d ", x);
}