#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N=300000+10;
LL f[N],g[N],s[N]; int n,x,a[N];
int main(){
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    for(int i=1;i<=n;i++){
        f[i]=max(f[i],f[i-1]+a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        g[i]=max(g[i],g[i+1]+a[i]);
    }
    LL mx=0,ans=0;
    for(int r=1;r<=n;r++){
        mx=max(mx,f[r]-x*s[r]);
        ans=max(ans, g[r+1]+x*s[r] + mx);
    }
    cout<<ans<<endl;
}