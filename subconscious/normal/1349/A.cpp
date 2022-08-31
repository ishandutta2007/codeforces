#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuck0
#define y0 fuck1
#define x1 fuck2
#define y1 fuck3
#define st first
#define nd second
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
typedef long double ld;
typedef __int128 i128;
const int N=1e6+5,inf=2e9+7;
int T,n,a[N];
ll ans;
int main(){
    T=1;
    rep(Cas,T){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        ans=1;
        ll tmp=1ll*a[1]*a[2];
        for(int pri=2;pri<=200000;++pri)if(tmp%pri==0){
            while(tmp%pri==0)tmp/=pri;
            int cnt0=inf,cnt1=inf;
            rep(i,n){
                int cnt=0,tp=a[i];
                while(tp%pri==0)++cnt,tp/=pri;
                if(cnt<cnt0)cnt1=cnt0,cnt0=cnt;
                else if(cnt<cnt1)cnt1=cnt;
            }
            rep(i,cnt1)ans*=pri;
        }
        printf("%lld\n",ans);
    }
    return 0;
}