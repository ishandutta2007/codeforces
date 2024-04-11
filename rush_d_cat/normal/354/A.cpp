#include <iostream>
#include <cstring>
using namespace std;
const int N=100000+10;
typedef long long LL;
int n,l,r,ql,qr,w[N];
LL s[N];
int main() {
    scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+w[i];
    LL ans=1e18;
    for(int i=0;i<=n;i++){
        LL tmp=s[i]*l+(s[n]-s[i])*r;
        if(i<(n-i)){
            tmp+=((n-i)-i-1)*qr;
        } else if(i>(n-i)){
            tmp+=(i-(n-i)-1)*ql;
        }
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
}