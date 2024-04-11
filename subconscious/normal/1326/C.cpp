#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuck1
#define y0 fuck2
#define x1 fuck3
#define y1 fuck4
#define mp make_pair
#define pb push_back
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=3e6+5,mod=998244353;
int a[N],n,k;
int main(){
    scanf("%d%d",&n,&k);
    rep(i,n)scanf("%d",a+i);
    k=n-k+1;
    ll ans1=0,ans2=1;
    rep(i,n)if(i>=k)ans1+=i;
    int cnt=0,now=1;
    while(a[now]<k)++now;
    for(;now<=n;++now)if(a[now]<k)++cnt;
        else ans2=1ll*ans2*(cnt+1)%mod,cnt=0;
    printf("%lld %lld\n",ans1,ans2);
    return 0;
}