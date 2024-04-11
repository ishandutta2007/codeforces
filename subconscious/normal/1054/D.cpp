#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fuckjsb
#define y1 fuckjtjl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=2e5+5,inf=0x3f3f3f3f,MOD=1e9+7;
int a[N],n,k,p,s[N];
int main(){
    scanf("%d%d",&n,&k);p=(1<<k)-1;
    rep(i,n)scanf("%d",a+i),a[i]^=a[i-1];
    ll ans=0;
    int top;
    s[top=1]=0;
    rep(i,n){
        int tmp=a[i];if(tmp>(tmp^p))tmp^=p;
        s[++top]=tmp;
    }
    sort(s+1,s+top+1);s[top+1]=-1;
    ans=1ll*top*(top-1)/2;
    int cnt=1;
    for(int i=2;i<=top+1;++i)
        if(s[i]==s[i-1])++cnt;
    else{
        ans-=1ll*(cnt/2)*(cnt/2-1)/2;
        ans-=1ll*((cnt+1)/2)*((cnt+1)/2-1)/2;
        cnt=1;
    }
    printf("%lld\n",ans);
    return 0;
}